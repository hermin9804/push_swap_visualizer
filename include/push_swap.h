/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:12:01 by mher              #+#    #+#             */
/*   Updated: 2022/04/15 19:26:45 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "data_struct.h"
# include "operator.h"
# include "initialize.h"

void		push_swap(t_info *info);
void		pb_smaller_than_pivot(t_info *info, int pivot);
void		pb_leave_three(t_info *info);
void		set_rotate_position(t_info *info, t_rotate rotate);
t_rotate	get_min_rotate_cnt(t_info *info);

#endif
