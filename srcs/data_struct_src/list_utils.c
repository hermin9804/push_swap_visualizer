/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:31:31 by mher              #+#    #+#             */
/*   Updated: 2022/04/22 15:49:26 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/data_struct.h"

t_list	*ft_lstnew(int data)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	new_list->data = data;
	new_list->next = 0;
	new_list->prev = 0;
	return (new_list);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstlast_cnt(t_list *lst, int cnt)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (i < cnt)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	t_list	*last;

	if (!lst || !new_list)
		return ;
	if (!*lst)
	{
		*lst = new_list;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new_list;
	new_list->prev = last;
}

void	ft_lstadd_front(t_list **lst, t_list *new_list)
{
	if (!lst || !new_list)
		return ;
	new_list->next = *lst;
	(*lst)->prev = new_list;
	*lst = new_list;
}
