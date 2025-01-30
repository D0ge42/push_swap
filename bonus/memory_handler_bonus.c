/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:23:05 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/30 21:39:43 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Function used to check if a certain char is present in a string*/

void	free_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i] && args)
		free(args[i]);
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

/*Function used to free stacks when something fails.
It will free based on a flag passed as a string. */

void	free_stacks(t_stack *stacks, char *which)
{
	if (!ft_strcmp(which, "A"))
	{
		free(stacks->a);
		free(stacks);
		exit(EXIT_SUCCESS);
	}
	else if (!ft_strcmp(which, "B"))
	{
		free(stacks->b);
		free(stacks);
		exit(EXIT_SUCCESS);
	}
	else if (!ft_strcmp(which, "Struct only"))
	{
		free(stacks);
		exit(EXIT_SUCCESS);
	}
	else
	{
		free(stacks->a);
		free(stacks->b);
		free(stacks);
		exit(EXIT_SUCCESS);
	}
}

/* Used to close and free. Prints "Error" on stderror if args are not valid.
Non valid args are:
some arguments are bigger than an integer and/or there are duplicates
arguments aren’t integers*/

void	close_and_free(t_stack *stacks, char **args, char *args_free)
{
	ft_putstr_fd("Error\n", 2);
	if (!ft_strcmp(args_free, "FREE ARGS"))
		free_args(args);
	free_stacks(stacks, "BOTH");
}

/* Util fuction to check if a num is:
bigger than int max
lower than int min */

int	is_int(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}
