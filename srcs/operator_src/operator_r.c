/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:19:35 by mher              #+#    #+#             */
/*   Updated: 2022/04/16 02:51:56 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	ra(t_info *info, char flag)
{
	if (flag == 'p')
		write(1, "ra\n", 3);
	rotate_stack(&info->a);
}

void	rb(t_info *info, char flag)
{
	if (flag == 'p')
		write(1, "rb\n", 3);
	rotate_stack(&info->b);
}

void	rr(t_info *info, char flag)
{
	if (flag == 'p')
		write(1, "rr\n", 3);
	rotate_stack(&info->a);
	rotate_stack(&info->b);
}
