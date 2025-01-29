/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:40:40 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/29 14:20:44 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	realloc_stack_b(t_stack *stacks)
{
	int				i;
	int				j;
	long long int	*tmp_array_B;

	tmp_array_B = malloc(sizeof(long long int) * (stacks->n_numbers_b));
	if (!tmp_array_B)
		free_stacks(stacks, "BOTH");
	i = 1;
	j = 0;
	while (i < (stacks->n_numbers_b))
	{
		tmp_array_B[j] = (stacks->b)[i];
		j++;
		i++;
	}
	free(stacks->b);
	stacks->n_numbers_b -= 1;
	stacks->b = malloc(sizeof(long long int) * (stacks->n_numbers_b));
	j = 0;
	while (j < (stacks->n_numbers_b))
	{
		(stacks->b)[j] = tmp_array_B[j];
		j++;
	}
	free(tmp_array_B);
}

void	realloc_stack_a(t_stack *stacks)
{
	int				i;
	int				j;
	long long int	*tmp_array_A;

	tmp_array_A = malloc(sizeof(long long int) * stacks->n_numbers_a);
	if (!tmp_array_A)
		free_stacks(stacks, "BOTH");
	i = 1;
	j = 0;
	while (i < (stacks->n_numbers_a))
	{
		tmp_array_A[j] = (stacks->a)[i];
		j++;
		i++;
	}
	free(stacks->a);
	stacks->n_numbers_a -= 1;
	stacks->a = malloc(sizeof(long long int) * (stacks->n_numbers_a));
	j = 0;
	while (j < (stacks->n_numbers_a))
	{
		(stacks->a)[j] = tmp_array_A[j];
		j++;
	}
	free(tmp_array_A);
}

void	push_a(t_stack *stacks)
{
	int				i;
	int				j;
	long long int	*tmp_array_A;

	tmp_array_A = malloc(sizeof(long long int) * (stacks->n_numbers_a + 1));
	if (!tmp_array_A)
		free_stacks(stacks, "BOTH");
	i = 1;
	j = 0;
	tmp_array_A[0] = (stacks->b)[0];
	realloc_stack_b(stacks);
	while (j < (stacks->n_numbers_a))
		tmp_array_A[i++] = (stacks->a)[j++];
	free(stacks->a);
	stacks->n_numbers_a += 1;
	(stacks->a) = malloc(sizeof(long long int) * (stacks->n_numbers_a));
	i = 0;
	while (i < stacks->n_numbers_a)
	{
		(stacks->a)[i] = tmp_array_A[i];
		i++;
	}
	free(tmp_array_A);
}

void	push_b(t_stack *stacks)
{
	int				i;
	int				j;
	long long int	*tmp_array_B;

	tmp_array_B = malloc(sizeof(long long int) * (stacks->n_numbers_b + 1));
	if (!tmp_array_B)
		free_stacks(stacks, "BOTH");
	i = 1;
	j = 0;
	tmp_array_B[0] = (stacks->a)[0];
	realloc_stack_a(stacks);
	while (j < (stacks->n_numbers_b))
		tmp_array_B[i++] = (stacks->b)[j++];
	free(stacks->b);
	stacks->n_numbers_b += 1;
	(stacks->b) = malloc(sizeof(long long int) * (stacks->n_numbers_b));
	i = 0;
	while (i < stacks->n_numbers_b)
	{
		(stacks->b)[i] = tmp_array_B[i];
		i++;
	}
	free(tmp_array_B);
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