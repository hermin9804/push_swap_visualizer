/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:53:03 by mher              #+#    #+#             */
/*   Updated: 2022/04/20 03:30:22 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <fcntl.h>

static void	run_op(t_info *info, char *op)
{
	if (!ft_strncmp(op, "sa\n", 3))
		sa(info, 'p');
	else if (!ft_strncmp(op, "sb\n", 3))
		sb(info, 'p');
	else if (!ft_strncmp(op, "ss\n", 3))
		ss(info, 'p');
	else if (!ft_strncmp(op, "pa\n", 3))
		pa(info, 'p');
	else if (!ft_strncmp(op, "pb\n", 3))
		pb(info, 'p');
	else if (!ft_strncmp(op, "ra\n", 3))
		ra(info, 'p');
	else if (!ft_strncmp(op, "rb\n", 3))
		rb(info, 'p');
	else if (!ft_strncmp(op, "rr\n", 3))
		rr(info, 'p');
	else if (!ft_strncmp(op, "rra\n", 4))
		rra(info, 'p');
	else if (!ft_strncmp(op, "rrb\n", 4))
		rrb(info, 'p');
	else if (!ft_strncmp(op, "rrr\n", 4))
		rrr(info, 'p');
	else
		error_exit("Error\n");
}


static void	print_stick(int	cnt)
{
	while (cnt--)
		write(1, "-", 1);
}

static void	print_space(int cnt)
{
	while (cnt--)
		write(1, " ", 1);
}

static void	braker(void)
{
	char	*brake;

	while(1)
	{
		brake = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(brake, "\n", 1))
			return ;
	}
}

static void	visualizer(const t_info *info)
{
	int		i;
	t_list	*a_cur;
	t_list	*b_cur;

	i = 0;
	a_cur = info->a.head;
	b_cur = info->b.head;
	system("clear");
	while (i < info->total_size)
	{
		if (0 < info->a.size && i < info->a.size)
			print_stick(a_cur->data);
		if (info->a.size > i)
			print_space(info->max - a_cur->data);
		else
			print_space(info->max);
		write(1, "|", 1);
		if (0 < info->b.size && i < info->b.size)
			print_stick(b_cur->data);
		write(1, "\n", 1);
		if (1 < info->a.size)
			a_cur = a_cur->next;
		if (1 < info->b.size)
			b_cur = b_cur->next;
		i++;
	}
}

static void	checker(t_info *info)
{
	char	*op;
	int	fd;
	int	cnt;

	op = 0;
	cnt = 0;
	fd = open("push_swap_out", O_RDONLY);
	if (fd < 0)
		error_exit("Error: file open\n");
	while (1)
	{
		visualizer(info);
		op = get_next_line(fd);
		if (!op)
			break ;
		run_op(info, op);
		braker();
		free(op);
		++cnt;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_info	info;
	char	*line;
	int		*nums;

	if (argc < 2)
		return (0);
	line = get_line_num(argc, argv);
	nums = get_nums(line, &info);
	init_stack(&info, nums);
	quick_sort(nums, 0, info.total_size - 1);
	check_dup(nums, info.total_size);
	init_pivot(&info, nums);
	checker(&info);
	if (info.b.size == 0 && check_ascending(&info, nums))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}
