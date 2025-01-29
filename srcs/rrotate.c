/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:25:33 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/29 20:05:18 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrotate_a(t_stack *stacks)
{
	int				j;
	int				i;
	long long int	*tmp_array_a;

	tmp_array_a = malloc(sizeof(long long int) * stacks->n_numbers_a);
	if (!tmp_array_a)
		free_stacks(stacks, "BOTH");
	j = 0;
	while (j < (stacks->n_numbers_a - 1))
	{
		tmp_array_a[j] = (stacks->a)[j];
		j++;
	}
	j = 0;
	i = 1;
	(stacks->a)[0] = (stacks->a)[stacks->n_numbers_a - 1];
	while (i < stacks->n_numbers_a)
		(stacks->a)[i++] = tmp_array_a[j++];
	free(tmp_array_a);
}

void	rrotate_b(t_stack *stacks)
{
	int				j;
	int				i;
	long long int	*tmp_array_b;

	tmp_array_b = malloc(sizeof(long long int) * stacks->n_numbers_b);
	if (!tmp_array_b)
		free_stacks(stacks, "BOTH");
	j = 0;
	while (j < (stacks->n_numbers_b - 1))
	{
		tmp_array_b[j] = (stacks->b)[j];
		j++;
	}
	j = 0;
	i = 1;
	(stacks->b)[0] = (stacks->b)[stacks->n_numbers_b - 1];
	while (i < stacks->n_numbers_b)
		(stacks->b)[i++] = tmp_array_b[j++];
	free(tmp_array_b);
}

void	rrotate(t_stack *stacks, char which)
{
	if (stacks->n_numbers_a >= 2 && which == 'a')
	{
		rrotate_a(stacks);
		ft_printf("rra\n");
	}
	else if (stacks->n_numbers_b >= 2 && which == 'b')
	{
		rrotate_b(stacks);
		ft_printf("rrb\n");
	}
	else if (stacks->n_numbers_b >= 2 && stacks->n_numbers_a >= 2
		&& which == BOTH)
	{
		rrotate_a(stacks);
		rrotate_b(stacks);
		ft_printf("rrr\n");
	}
}
