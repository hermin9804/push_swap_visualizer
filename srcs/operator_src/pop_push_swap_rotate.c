/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_push_swap_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:16:34 by mher              #+#    #+#             */
/*   Updated: 2022/04/15 16:44:01 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	swap_stack(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = tmp;
}

void	push_stack(t_stack *dest, t_stack *from)
{
	t_list	*tmp;

	if (from->size == 0)
		return ;
	if (dest->size == 0)
	{
		dest->head = pop_stack(from);
		dest->size++;
		return ;
	}
	ft_lstadd_front(&dest->head, pop_stack(from));
	tmp = ft_lstlast_cnt(dest->head, dest->size);
	dest->head->prev = tmp;
	tmp->next = dest->head;
	dest->size++;
}

t_list	*pop_stack(t_stack *stack)
{
	t_list	*pop;

	pop = stack->head;
	if (stack->size == 1)
	{
		stack->head = 0;
	}
	else if (stack->size == 2)
	{
		stack->head = stack->head->next;
	}
	else
	{
		stack->head->prev->next = stack->head->next;
		stack->head->next->prev = stack->head->prev;
		stack->head = stack->head->next;
	}
	stack->size--;
	pop->next = 0;
	pop->prev = 0;
	return (pop);
}

void	rotate_stack(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->head->next;
}

void	reverse_rotate_stack(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->head->prev;
}
