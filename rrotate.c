/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:25:33 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/27 14:46:44 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_stack *stacks)
{
	int				j;
	int				i;
	long long int	*tmp_arrayA;

	tmp_arrayA = malloc(sizeof(long long int) * stacks->n_numbers_a);
	if (!tmp_arrayA)
		free_stacks(stacks, "BOTH");
	j = 0;
	// We first copy everything but last element into a temporary array.
	while (j < (stacks->n_numbers_a - 1))
	{
		tmp_arrayA[j] = (stacks->a)[j];
		j++;
	}
	j = 0;
	i = 1;
	// First one become last one
	(stacks->a)[0] = (stacks->a)[stacks->n_numbers_a - 1];
	// We now copy from element at index 1 to the end
	while (i < stacks->n_numbers_a)
		(stacks->a)[i++] = tmp_arrayA[j++];
	free(tmp_arrayA);
}

void	rrotate_b(t_stack *stacks)
{
	int				j;
	int				i;
	long long int	*tmp_arrayB;

	tmp_arrayB = malloc(sizeof(long long int) * stacks->n_numbers_b);
	if (!tmp_arrayB)
		free_stacks(stacks, "BOTH");
	j = 0;
	// We first copy everything but last element into a temporary array.
	while (j < (stacks->n_numbers_b - 1))
	{
		tmp_arrayB[j] = (stacks->b)[j];
		j++;
	}
	j = 0;
	i = 1;
	// First one become last one
	(stacks->b)[0] = (stacks->b)[stacks->n_numbers_b - 1];
	// We now copy from element at index 1 to the end
	while (i < stacks->n_numbers_b)
		(stacks->b)[i++] = tmp_arrayB[j++];
	free(tmp_arrayB);
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