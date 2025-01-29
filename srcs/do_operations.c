/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:36:01 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/29 20:05:37 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_rrotations(t_stack *stacks, int common_rrrotation, int rot_a,
		int rot_b)
{
	int	residual_a;
	int	residual_b;

	residual_b = 0;
	residual_a = 0;
	common_rrrotation = min(get_abs(rot_a), get_abs(rot_b));
	residual_a = get_abs(rot_a) - common_rrrotation;
	residual_b = get_abs(rot_b) - common_rrrotation;
	while (common_rrrotation--)
		rrotate(stacks, BOTH);
	while (residual_b--)
		rrotate(stacks, 'b');
	while (residual_a--)
		rrotate(stacks, 'a');
}

void	do_rotations(t_stack *stacks, int common_rrrotation, int rot_a,
		int rot_b)
{
	int	residual_a;
	int	residual_b;

	residual_b = 0;
	residual_a = 0;
	common_rrrotation = min(rot_a, rot_b);
	residual_a = rot_a - common_rrrotation;
	residual_b = rot_b - common_rrrotation;
	while (common_rrrotation--)
		rotate(stacks, BOTH);
	while (residual_b--)
		rotate(stacks, 'b');
	while (residual_a--)
		rotate(stacks, 'a');
}

void	rotate_a_and_b(t_stack *stacks, int rot_a, int rot_b)
{
	if (rot_a >= 0 && rot_b <= 0)
	{
		rot_b = get_abs(rot_b);
		while (rot_a--)
			rotate(stacks, 'a');
		while (rot_b--)
			rrotate(stacks, 'b');
	}
	else if (rot_a <= 0 && rot_b >= 0)
	{
		rot_a = get_abs(rot_a);
		while (rot_a--)
			rrotate(stacks, 'a');
		while (rot_b--)
			rotate(stacks, 'b');
	}
}
