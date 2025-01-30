/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:16:04 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/29 22:06:42 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	handle_push(t_stack *stacks)
{
	if (stacks->n_numbers_a > 5)
	{
		while (stacks->n_numbers_a > 3)
		{
			find_biggest_and_lowest(stacks);
			if (stacks->index_max == 0 || stacks->index_min == 0)
				rotate(stacks, 'a');
			else
				push(stacks, 'b');
		}
	}
	else
	{
		while (stacks->n_numbers_a > 3)
			push(stacks, 'b');
	}
}

void	find_biggest_and_lowest(t_stack *stacks)
{
	int	max;
	int	min;
	int	i;

	max = stacks->a[0];
	min = stacks->a[0];
	i = stacks->n_numbers_a - 1;
	stacks->index_max = 0;
	stacks->index_min = 0;
	while (i)
	{
		if (stacks->a[i] > max)
		{
			max = stacks->a[i];
			stacks->index_max = i;
		}
		else if (stacks->a[i] < min)
		{
			min = stacks->a[i];
			stacks->index_min = i;
		}
		i--;
	}
}

void	sort_stack_a(t_stack *stacks)
{
	if (stacks->a[0] > stacks->a[1] && stacks->a[0] > stacks->a[2])
		rotate(stacks, 'a');
	else if (stacks->a[1] > stacks->a[0] && stacks->a[1] > stacks->a[2])
		rrotate(stacks, 'a');
	if (stacks->a[0] > stacks->a[1])
		swap(stacks, 'a');
}

int	is_topush_biggest(t_stack *stacks, int index)
{
	long long	num_to_push;
	int			i;

	num_to_push = (stacks->b)[index];
	i = 0;
	while (i < stacks->n_numbers_a)
	{
		if ((stacks->a)[i] > num_to_push)
			return (0);
		i++;
	}
	return (1);
}

int	is_topush_smallest(t_stack *stacks, int index)
{
	long long	num_to_push;
	int			i;

	num_to_push = (stacks->b)[index];
	i = 0;
	while (i < stacks->n_numbers_a)
	{
		if ((stacks->a)[i] < num_to_push)
			return (0);
		i++;
	}
	return (1);
}
