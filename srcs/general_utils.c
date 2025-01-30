/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:13:21 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/30 21:42:08 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Atoll is atoi to long long num. Similar to atoi
but it checks also if resulting num is in the integers range.
This has to be done inside the function cause the resulting number can overflow
and this can resulting in accepting args that are not valid.
It will also check if there are also non digits characters.
In case of error it will free, print "Error" and exit the main program. */

long long	ft_atoll(char *str, t_stack *stacks, char **args)
{
	long long	num;
	int			sign;
	int			i;

	if (ft_strlen(str) == 0)
		close_and_free(stacks, args, "FREE ARGS");
	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	handle_sign(str, &i, &sign);
	if (!ft_isdigit(str[i]))
		close_and_free(stacks, args, "FREE ARGS");
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			close_and_free(stacks, args, "FREE ARGS");
		num = (num * 10) + (str[i] - '0');
		if (!is_int(num * sign))
			close_and_free(stacks, args, "FREE ARGS");
		i++;
	}
	return (num * sign);
}

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

int	strchar(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
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
