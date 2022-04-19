/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:18:52 by mher              #+#    #+#             */
/*   Updated: 2022/04/16 03:32:38 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	pa(t_info *info, char flag)
{
	if (flag == 'p')
		write(1, "pa\n", 3);
	push_stack(&info->a, &info->b);
}

void	pb(t_info *info, char flag)
{
	if (flag == 'p')
		write(1, "pb\n", 3);
	push_stack(&info->b, &info->a);
}
