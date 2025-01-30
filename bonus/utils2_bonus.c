/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:13:21 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/30 18:30:50 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* Function that will count the total numbers we've to fill the stack with.
It will count "1 2 3" as 3 number and same goes for 1 2 3. */

int	count_nums(int ac, char **av)
{
	char	**args;
	int		i;
	int		total_nums;
	int		k;

	i = 1;
	total_nums = 0;
	args = NULL;
	while (i < ac)
	{
		k = 0;
		args = ft_split(av[i], ' ');
		while (args[k])
		{
			k++;
			total_nums++;
		}
		i++;
		free_args(args);
	}
	return (total_nums);
}
/*Function used to free arguments we get by using split on **av */

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/*Check if malloc fails when allocating memory for both stacks*/

void	check_malloc_fail(t_stack *stacks)
{
	if (!stacks->a)
	{
		free(stacks);
		exit(EXIT_FAILURE);
	}
	else if (!stacks->b)
	{
		free(stacks->a);
		free(stacks);
		exit(EXIT_FAILURE);
	}
}

int	min(int a, int b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

int	find_smallest_n_of_moves(t_stack *stacks, int *total_moves)
{
	int	i;
	int	index;
	int	minor;

	i = -1;
	index = 0;
	minor = 2147483647;
	while (++i < stacks->n_numbers_b)
	{
		if (total_moves[i] < minor)
		{
			minor = total_moves[i];
			index = i;
		}
	}
	return (index);
}
