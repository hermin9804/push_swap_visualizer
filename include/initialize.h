/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:18:22 by mher              #+#    #+#             */
/*   Updated: 2022/04/18 14:21:51 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H

# include <unistd.h>
# include <limits.h>
# include "data_struct.h"
# include "../lib/libft/include/libft.h"

char	*get_line_num(int argc, char **argv);
int		*get_nums(char *line, t_info *info);
void	init_stack(t_info *info, int *nums);
void	init_pivot(t_info *info, int *nums);
void	check_dup(int *nums, int size);
int		check_ascending(t_info *info, int *nums);
int		check_num_atoi(const char *str);
void	quick_sort(int *arr, int start, int end);
void	error_exit(const char *msg);

#endif
