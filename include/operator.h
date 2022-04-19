/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:19:05 by mher              #+#    #+#             */
/*   Updated: 2022/04/16 19:06:06 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include "unistd.h"
# include "data_struct.h"

void	swap_stack(t_stack *stack);
t_list	*pop_stack(t_stack *stack);
void	push_stack(t_stack *dest, t_stack *from);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);
void	sa(t_info *info, char flag);
void	sb(t_info *info, char flag);
void	ss(t_info *info, char flag);
void	pa(t_info *info, char flag);
void	pb(t_info *info, char flag);
void	ra(t_info *info, char flag);
void	rb(t_info *info, char flag);
void	rr(t_info *info, char flag);
void	rra(t_info *info, char flag);
void	rrb(t_info *info, char flag);
void	rrr(t_info *info, char flag);

#endif
