/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:20:22 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/25 12:22:51 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else if (stacks->n_numbers_b >= 2
	&& stacks->n_numbers_a >= 2 && which == BOTH)
	{
		rotate_a(stacks);
		rotate_b(stacks);
		ft_printf("rr\n");
	}
}

void	rotate_a(t_stack *stacks)
{
	int j;
	int i;
	long long int tmp_arrayA[stacks->n_numbers_a];

	j = 0;
	i = 1;
	// We first copy everything but the first  element into a temporary array.
	while (i < (stacks->n_numbers_a))
	{
		tmp_arrayA[j] = (stacks->a)[i];
		j++;
		i++;
	}
	j = 0;
	i = 1;
	// Last one becomes first one 1 2 3 4 5  -->  2 3 4 5 1
	(stacks->a)[stacks->n_numbers_a - 1] = (stacks->a)[0];
	// We now copy from element at index 1 up to the end.
	while (i < stacks->n_numbers_a)
	{
		(stacks->a)[i] = tmp_arrayA[j];
		i++;
		j++;
	}
}

void	rotate_b(t_stack *stacks)
{
	int j;
	int i;
	long long int tmp_arrayB[stacks->n_numbers_b];

	j = 0;
	i = 1;
	// We first copy everything but the first  element into a temporary array.
	while (i < (stacks->n_numbers_b))
	{
		tmp_arrayB[j] = (stacks->b)[i];
		j++;
		i++;
	}
	j = 0;
	i = 1;
	// Last one becomes first one 1 2 3 4 5  -->  2 3 4 5 1
	(stacks->b)[stacks->n_numbers_b - 1] = (stacks->b)[0];
	// We now copy from element at index 1 up to the end.
	while (i < stacks->n_numbers_b)
	{
		(stacks->b)[i] = tmp_arrayB[j];
		i++;
		j++;
	}
	i = 0;
}