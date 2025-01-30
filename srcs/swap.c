/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:40:40 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/30 15:33:38 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_ss(t_stack *stacks)
{
	int	tmp_a;
	int	tmp_b;

	tmp_a = 0;
	tmp_b = 0;
	tmp_a = (stacks->a)[0];
	(stacks->a)[0] = (stacks->a)[1];
	(stacks->a)[1] = tmp_a;
	tmp_b = (stacks->b)[0];
	(stacks->b)[0] = (stacks->b)[1];
	(stacks->b)[1] = tmp_b;
	ft_printf("ss\n", 1);
}

void	swap_a(t_stack *stacks)
{
	int	tmp_a;

	tmp_a = 0;
	tmp_a = (stacks->a)[0];
	(stacks->a)[0] = (stacks->a)[1];
	(stacks->a)[1] = tmp_a;
	ft_printf("sa\n", 1);
}

void	swap_b(t_stack *stacks)
{
	int	tmp_b;

	tmp_b = 0;
	tmp_b = (stacks->b)[0];
	(stacks->b)[0] = (stacks->b)[1];
	(stacks->b)[1] = tmp_b;
	ft_printf("sb\n", 1);
}

void	swap(t_stack *stacks, char which)
{
	if (stacks->n_numbers_a > 1 && which == 'a')
		swap_a(stacks);
	else if (stacks->n_numbers_b > 1 && which == 'b')
		swap_b(stacks);
	else if (stacks->n_numbers_b > 1
		&& stacks->n_numbers_a > 1 && which == BOTH)
		swap_ss(stacks);
}
