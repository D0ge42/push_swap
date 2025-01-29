/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:40:40 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/29 14:16:55 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	swap_ss(t_stack *stacks)
{
	int	tmp_A;
	int	tmp_B;

	tmp_A = 0;
	tmp_B = 0;
	tmp_A = (stacks->a)[0];
	(stacks->a)[0] = (stacks->a)[1];
	(stacks->a)[1] = tmp_A;
	tmp_B = (stacks->b)[0];
	(stacks->b)[0] = (stacks->b)[1];
	(stacks->b)[1] = tmp_B;
	ft_printf("ss\n", 1);
}

void	swap_a(t_stack *stacks)
{
	int	tmp_A;

	tmp_A = 0;
	tmp_A = (stacks->a)[0];
	(stacks->a)[0] = (stacks->a)[1];
	(stacks->a)[1] = tmp_A;
	ft_printf("sa\n", 1);
}

void	swap_b(t_stack *stacks)
{
	int	tmp_B;

	tmp_B = 0;
	tmp_B = (stacks->b)[0];
	(stacks->b)[0] = (stacks->b)[1];
	(stacks->b)[1] = tmp_B;
	ft_printf("sb\n", 1);
}

void	swap(t_stack *stacks, char which)
{
	if (stacks->n_numbers_a > 1 && which == 'a')
		swap_a(stacks);
	else if (stacks->n_numbers_b > 1 && which == 'b')
		swap_b(stacks);
	else if (stacks->n_numbers_b > 1 && which == 'b' && stacks->n_numbers_a > 1
		&& which == 'a' && which == BOTH)
		swap_ss(stacks);
}
