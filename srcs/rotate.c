/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:20:22 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/29 20:05:24 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack *stacks, char which)
{
	if (stacks->n_numbers_a >= 2 && which == 'a')
	{
		rotate_a(stacks);
		ft_printf("ra\n");
	}
	if (stacks->n_numbers_b >= 2 && which == 'b')
	{
		rotate_b(stacks);
		ft_printf("rb\n");
	}
	else if (stacks->n_numbers_b >= 2 && stacks->n_numbers_a >= 2
		&& which == BOTH)
	{
		rotate_a(stacks);
		rotate_b(stacks);
		ft_printf("rr\n");
	}
}

void	rotate_a(t_stack *stacks)
{
	int				j;
	int				i;
	long long int	*tmp_array_a;

	tmp_array_a = malloc(sizeof(long long int) * (stacks->n_numbers_a));
	if (!tmp_array_a)
		free_stacks(stacks, "BOTH");
	j = 0;
	i = 1;
	while (i < (stacks->n_numbers_a))
	{
		tmp_array_a[j] = (stacks->a)[i];
		j++;
		i++;
	}
	j = 0;
	i = 0;
	(stacks->a)[stacks->n_numbers_a - 1] = (stacks->a)[0];
	while (i < stacks->n_numbers_a - 1)
	{
		(stacks->a)[i] = tmp_array_a[i];
		i++;
	}
	free(tmp_array_a);
}

void	rotate_b(t_stack *stacks)
{
	int				j;
	int				i;
	long long int	*tmp_array_b;

	tmp_array_b = malloc(sizeof(long long int) * (stacks->n_numbers_b));
	if (!tmp_array_b)
		free_stacks(stacks, "BOTH");
	j = 0;
	i = 1;
	while (i < (stacks->n_numbers_b))
	{
		tmp_array_b[j] = (stacks->b)[i];
		j++;
		i++;
	}
	j = 0;
	i = 0;
	(stacks->b)[stacks->n_numbers_b - 1] = (stacks->b)[0];
	while (i < stacks->n_numbers_b - 1)
	{
		(stacks->b)[i] = tmp_array_b[i];
		i++;
	}
	free(tmp_array_b);
}
