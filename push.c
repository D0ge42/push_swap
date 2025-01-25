/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:40:40 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/24 17:59:51 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	realloc_stack_b(t_stack *stacks)
{
	int				i;
	int				j;
	long long int	tmp_arrayB[stacks->n_numbers_b];

	i = 1;
	j = 0;
	// Salvo tutti i valori di B in un temp array a partire da i + 1;
	while (i < (stacks->n_numbers_b))
	{
		tmp_arrayB[j] = (stacks->b)[i];
		j++;
		i++;
	}
	// Remove shifted element from b.
	free(stacks->b);
	stacks->n_numbers_b -= 1;
	stacks->b = malloc(sizeof(long long int) * (stacks->n_numbers_b));
	// Now we've to copy from tmp_arrayB+1 into the newly allocated stackB
	j = 0;
	while (j < (stacks->n_numbers_b))
	{
		(stacks->b)[j] = tmp_arrayB[j];
		j++;
	}
}

void	realloc_stack_a(t_stack *stacks)
{
	int				i;
	int				j;
	long long int	tmp_arrayA[stacks->n_numbers_a];

	i = 1;
	j = 0;
	// Salvo tutti i valori di A in un temp array a partire da i + 1;
	while (i < (stacks->n_numbers_a))
	{
		tmp_arrayA[j] = (stacks->a)[i];
		j++;
		i++;
	}
	free(stacks->a);
	stacks->n_numbers_a -= 1;
	stacks->a = malloc(sizeof(long long int) * (stacks->n_numbers_a));
	// Now we've to copy from tmp_arrayB+1 into the newly allocated stackB
	j = 0;
	while (j < (stacks->n_numbers_a))
	{
		(stacks->a)[j] = tmp_arrayA[j];
		j++;
	}
}

void	push_a(t_stack *stacks)
{
	int				i;
	int				j;
	long long int	tmp_arrayA[stacks->n_numbers_a + 1];

	i = 1;
	j = 0;
	tmp_arrayA[0] = (stacks->b)[0];
	realloc_stack_b(stacks);
	// Once that is done we can push the new
	while (j < (stacks->n_numbers_a))
		tmp_arrayA[i++] = (stacks->a)[j++];
	free(stacks->a);
	stacks->n_numbers_a += 1;
	(stacks->a) = malloc(sizeof(long long int) * (stacks->n_numbers_a));
	i = 0;
	while (i < stacks->n_numbers_a)
	{
		(stacks->a)[i] = tmp_arrayA[i];
		i++;
	}
}

void	push_b(t_stack *stacks)
{
	int				i;
	int				j;
	long long int	tmp_arrayB[stacks->n_numbers_b + 1];

	i = 1;
	j = 0;
	tmp_arrayB[0] = (stacks->a)[0];
	// Free and reallocate a but with n_numbers - 1 since we shift  1 digits.
	realloc_stack_a(stacks);
	while (j < (stacks->n_numbers_b))
		tmp_arrayB[i++] = (stacks->b)[j++];
	free(stacks->b);
	stacks->n_numbers_b += 1;
	(stacks->b) = malloc(sizeof(long long int) * (stacks->n_numbers_b));
	i = 0;
	while (i < stacks->n_numbers_b)
	{
		(stacks->b)[i] = tmp_arrayB[i];
		i++;
	}
}


void	push(t_stack *stacks, char which)
{
	if (stacks->n_numbers_b >= 1 && which == 'a')
	{
		push_a(stacks);
		ft_printf("pa\n");
	}
	else if (stacks->n_numbers_a >= 1 && which == 'b')
	{
		push_b(stacks);
		ft_printf("pb\n");
	}
}