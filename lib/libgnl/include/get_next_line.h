/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:32:44 by mher              #+#    #+#             */
/*   Updated: 2022/04/19 18:02:42 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif


typedef struct s_fd_lst
{
	int				fd;
	char			*keep;
	struct s_fd_lst	*prev;
	struct s_fd_lst	*next;
}	t_fd_lst;

char			*get_line(char *keep);
char			*read_file(int fd, char *keep);
t_fd_lst		*find_fd(int fd, t_fd_lst *head);
char			*gnl_or_del(t_fd_lst **fd_lst);
char			*get_next_line(int fd);

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
