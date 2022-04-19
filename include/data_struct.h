/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:28:10 by mher              #+#    #+#             */
/*   Updated: 2022/04/18 14:21:29 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int		size;
	t_list	*head;
}	t_stack;

typedef struct s_info
{
	int		total_size;
	int		max;
	int		min;
	int		f_pivot;
	int		s_pivot;
	t_stack	a;
	t_stack	b;
}	t_info;

typedef struct s_op
{
	int	r;
	int	rr;
}	t_op;

typedef struct s_rotate
{
	t_op	a;
	t_op	b;
}	t_rotate;

t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstlast_cnt(t_list *lst, int cnt);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

#endif
