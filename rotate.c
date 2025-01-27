/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:20:22 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/27 15:45:47 by lonulli          ###   ########.fr       */
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
	long long int	*tmp_arrayA;

	tmp_arrayA = malloc(sizeof(long long int) * (stacks->n_numbers_a));
	if (!tmp_arrayA)
		free_stacks(stacks, "BOTH");
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
	i = 0;
	// Last one becomes first one 1 2 3 4 5  -->  2 3 4 5 1
	(stacks->a)[stacks->n_numbers_a - 1] = (stacks->a)[0];
	// We now copy from element at index 1 up to the end.
	while (i < stacks->n_numbers_a - 1)
	{
		(stacks->a)[i] = tmp_arrayA[i];
		i++;
	}
	free(tmp_arrayA);
}

void	rotate_b(t_stack *stacks)
{
	int j;
	int i;
	long long int *tmp_arrayB;
	tmp_arrayB = malloc(sizeof(long long int) * (stacks->n_numbers_b));
	if (!tmp_arrayB)
		free_stacks(stacks, "BOTH");

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
	i = 0;
	// Last one becomes first one 1 2 3 4 5  -->  x x x x 1
	(stacks->b)[stacks->n_numbers_b - 1] = (stacks->b)[0];
	// We now copy from element at index 1 up to the end.
	while (i < stacks->n_numbers_b - 1)
	{
		(stacks->b)[i] = tmp_arrayB[i];
		i++;
	}
	free(tmp_arrayB);
}