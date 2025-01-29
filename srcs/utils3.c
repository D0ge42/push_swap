/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:20:01 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/29 20:04:56 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_already_sorted(t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->n_numbers_a - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ordinate_stack(t_stack *stacks)
{
	int	ordinate;

	ordinate = 0;
	ordinate = find_lowest_num_a(stacks);
	while (ordinate)
	{
		rotate(stacks, 'a');
		ordinate--;
	}
}

int	find_lowest_num_a(t_stack *stacks)
{
	int	i;
	int	lowest;
	int	index;
	int	to_check;

	i = 0;
	lowest = (stacks->a)[0];
	index = 0;
	while (i < stacks->n_numbers_a)
	{
		to_check = (stacks->a)[i];
		if (to_check < lowest)
		{
			lowest = to_check;
			index = i;
		}
		i++;
	}
	return (index);
}

void	handle_sign(char *str, int *i, int *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	get_abs(long long int num)
{
	if (num < 0)
		return (num *= -1);
	return (num);
}
