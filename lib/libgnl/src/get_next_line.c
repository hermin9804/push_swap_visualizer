/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:31:47 by mher              #+#    #+#             */
/*   Updated: 2022/04/19 18:01:12 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *keep)
{
	char	*line;
	size_t	i;

	i = 0;
	while (keep[i] != '\n' && keep[i])
		++i;
	if (keep[i] == '\n')
		++i;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
	{
		free(keep);
		keep = 0;
		return (0);
	}
	i = 0;
	while (keep[i] != '\n' && keep[i])
	{
		line[i] = keep[i];
		i++;
	}
	if (keep[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*read_file(int fd, char *keep)
{
	char	*buff;
	char	*temp;
	ssize_t	read_size;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	read_size = read(fd, buff, BUFFER_SIZE);
	while (read_size > 0)
	{
		buff[read_size] = '\0';
		temp = keep;
		keep = ft_strjoin(temp, buff);
		free(temp);
		temp = 0;
		if (ft_strchr(keep, '\n') || !keep)
			break ;
		read_size = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	buff = 0;
	if (read_size < 0)
		return (0);
	return (keep);
}

t_fd_lst	*find_fd(int fd, t_fd_lst *head)
{
	t_fd_lst	*temp;

	temp = head->next;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = (t_fd_lst *)malloc(sizeof(t_fd_lst));
	if (!temp)
		return (0);
	temp->fd = fd;
	temp->keep = 0;
	temp->prev = head;
	temp->next = head->next;
	if (head->next)
		head->next->prev = temp;
	head->next = temp;
	return (temp);
}

char	*gnl_or_del(t_fd_lst **fd_lst)
{
	char	*line;
	char	*temp;

	if ((*fd_lst)->keep)
	{
		line = get_line((*fd_lst)->keep);
		if (!line)
			return (0);
		temp = (*fd_lst)->keep;
		(*fd_lst)->keep = ft_strdup(temp + ft_strlen(line));
		free(temp);
		temp = 0;
		if (!((*fd_lst)->keep))
			return (0);
		return (line);
	}
	else
	{
		(*fd_lst)->prev->next = (*fd_lst)->next;
		if ((*fd_lst)->next)
			(*fd_lst)->next->prev = (*fd_lst)->prev;
		free(*fd_lst);
		*fd_lst = 0;
		return (0);
	}
}

char	*get_next_line(int fd)
{
	static t_fd_lst	head;
	t_fd_lst		*fd_lst;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	fd_lst = find_fd(fd, &head);
	if (!fd_lst)
		return (0);
	fd_lst->keep = read_file(fd, fd_lst->keep);
	//read_file에서 buff 할당실패 || keep 할당 실패
	if (!(fd_lst->keep))
		return (gnl_or_del(&fd_lst));
	//read_file에서 empty_file || eof를 만난후 다시 읽은 경우 keep에 '\0' free
	if (!*(fd_lst->keep))
	{
		free(fd_lst->keep);
		fd_lst->keep = 0;
		return (gnl_or_del(&fd_lst));
	}
	//read_file에서 한줄을 잘 읽고 keep에 문자열이 저장된경우
	return (gnl_or_del(&fd_lst));
}
