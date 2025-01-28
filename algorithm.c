/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:10:18 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/28 14:58:13 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// We first push two numbers on stack b --> 2x pb
// Now we''ll have to count all the time.
// We''ll calculate for every number how many operations needed.

// Function to check if current number is on STACK_A is going to be
// Highest in STACK_B. In this case it should be placed on top of STACK_B biggest n.

/*Will check if the highest number in STACK_B is placed on top.*/
void	sort_stack_a(t_stack *stacks);
int		find_lowest_num_a(t_stack *stacks);
int		get_abs(long long int num);
int	find_biggest_num_a(t_stack *stacks);

void	sort_stack_a(t_stack *stacks)
{
	if (stacks->a[0] > stacks->a[1] && stacks->a[0] > stacks->a[2])
		rotate(stacks, 'a');
	else if (stacks->a[1] > stacks->a[0] && stacks->a[1] > stacks->a[2])
		rrotate(stacks, 'a');
	if (stacks->a[0] > stacks->a[1])
		swap(stacks, 'a');
}

int	is_topush_biggest(t_stack *stacks, int index)
{
	long long	num_to_push;
	int			i;

	num_to_push = (stacks->b)[index];
	i = 0;
	while (i < stacks->n_numbers_a)
	{
		if (!(num_to_push > (stacks->a)[i]))
			return (0);
		i++;
	}
	return (1);
}
int	is_topush_smallest(t_stack *stacks, int index)
{
	long long	num_to_push;
	int			i;

	num_to_push = (stacks->b)[index];
	i = 0;
	while (i < stacks->n_numbers_a)
	{
		if (!(num_to_push < (stacks->a)[i]))
			return (0);
		i++;
	}
	return (1);
}


int	num_rotation_b(t_stack *stacks, int index)
{
	int	rotations;

	rotations = index;
	if (rotations > get_abs(rotations - stacks->n_numbers_b))
		rotations -= stacks->n_numbers_b;
	return (rotations);
}

int	num_rotation_a(t_stack *stacks, int index)
{
	long long int	num;
	int				i;
	int				rotation;

	num = (stacks->b)[index];
	i = 1;
	if (is_topush_smallest(stacks, index) || is_topush_biggest(stacks, index))
	{
		
		rotation = (find_lowest_num_a(stacks));
		if (rotation == 0)
			return (0);
		if (rotation > get_abs(rotation - stacks->n_numbers_a))
		{
			rotation -= stacks->n_numbers_a;
			return (rotation);
		}
		return rotation;
	}
	while (i < stacks->n_numbers_a)
	{
		if (num > (stacks->a)[i - 1] && num < (stacks->a)[i])
			break ;
		i++;
	}
	if (i > get_abs(i - stacks->n_numbers_a))
		i = i - stacks->n_numbers_a;
	return (i);
}

void	move_parser(t_stack *stacks, int *total_moves)
{
	int	i;
	int	rot_a;
	int	rot_b;
	int	common_rrrotation;
	// int	residual_a;
	// int	residual_b;
	i = 0;
	while (i < stacks->n_numbers_b)
	{
		rot_a = num_rotation_a(stacks, i);
		rot_b = num_rotation_b(stacks, i);
		// ft_printf("Number %i requires ROT_A = %i and ROT_B = %i\n",(stacks->b)[i],rot_a,rot_b);
		if (rot_a < 0 && rot_b < 0)
		{
			common_rrrotation = max(get_abs(rot_a),get_abs(rot_b));
			// residual_a = common_rrrotation - get_abs(rot_a); // Use
			// residual_b = common_rrrotation - get_abs(rot_b);
			total_moves[i] = common_rrrotation;
		}
		else if (rot_a > 0 && rot_b > 0)
		{
			common_rrrotation = max(rot_a, rot_b);
			// residual_a = common_rrrotation - rot_a;
			// residual_b = common_rrrotation - rot_b;
			total_moves[i] = common_rrrotation;
		}
		else
			total_moves[i] = (get_abs(rot_a)) + get_abs(rot_b);
		i++;
	}
	i = 0;
	while(i < stacks->n_numbers_b)
	{
		ft_printf("Total moves %i\n",total_moves[i]);
		i++;
	}
}


void	find_optimal_move(t_stack *stacks, int *total_moves)
{
	int i = 0;
	int index = 0;
	int minor =  total_moves[0];
	int residual_a = 0;
	int residual_b = 0;
	int common_rrrotation = 0;
	while(i < stacks->n_numbers_b)
	{
		// if we enter this if it means we've found a better move.
		if (total_moves[i] < minor)
		{
			minor = total_moves[i];
			index = i;
		}
		i++;
	}
	//Min -> Index of the best move in total moves.
	int rot_a = num_rotation_a(stacks, index); // --> Num of single rotations for A
	int rot_b = num_rotation_b(stacks, index); // --> Num of single rotations for B.
	// if (rot_a < 0)
	// 	rot_a+=plus_rrotate_a;
	// else if (rot_a > 0)
	// 	rot_a+=plus_rotate_a;
		// ft_printf("Number %i requires ROT_A = %i and ROT_B = %i\n",(stacks->b)[i],rot_a,rot_b);
	if (rot_a < 0 && rot_b < 0)
	{
		common_rrrotation = max(get_abs(rot_a),get_abs(rot_b));
		residual_a = common_rrrotation - get_abs(rot_a); // Use
		residual_b = common_rrrotation - get_abs(rot_b);
		int rest = max(get_abs(residual_a),get_abs(residual_b));
		while(common_rrrotation--)
			rrotate(stacks, BOTH);
		if(!residual_a)
		{
			while(rest--)
				rrotate(stacks,'b');
		}
		else
		{
			while(rest--)
				rrotate(stacks, 'a');
	}
	}
	else if (rot_a > 0 && rot_b > 0)
	{
		common_rrrotation = max(rot_a, rot_b);
		residual_a = common_rrrotation - rot_a;
		residual_b = common_rrrotation - rot_b;
		int common = common_rrrotation;
		int rest = max(residual_a,residual_b);
		while(common--)
			rotate(stacks, BOTH);
		if(!residual_a)
		{
			while(rest--)
				rotate(stacks,'b');
		}
		else
		{
			while(rest--)
				rotate(stacks, 'a');
		}
	}
	else  if (rot_a >= 0 && rot_b <= 0)
	{
		rot_b = get_abs(rot_b);
		while(rot_a)
		{
			rotate(stacks,'a');
			rot_a--;
		}
		while(rot_b)
		{
			rrotate(stacks,'b');
			rot_b--;
		}
	}
	else  if (rot_a <= 0 && rot_b >= 0)
	{
		rot_a = get_abs(rot_a);
		while(rot_a)
		{
			rrotate(stacks,'a');
			rot_a--;
		}
		while(rot_b)
		{
			rotate(stacks,'b');
			rot_b--;
		}
	}
}
void	algorithm(t_stack *stacks)
{
	int	*total_moves;

	// int	ordinate;
	// This array will be filled with the total moves required for each number.
	// We push until 3 numbers are left in the stack.
	while (stacks->n_numbers_a > 3)
		push(stacks, 'b');
	total_moves = malloc(sizeof(int) * stacks->n_numbers_b);
	// Once we've pushed all the numbers but 3 in b, it's time to sort stack A.
	sort_stack_a(stacks);
	int i = stacks->n_numbers_b;
	while(i--)
	{
		move_parser(stacks, total_moves);
		find_optimal_move(stacks, total_moves);
		push(stacks, 'a');
	}
	int ordinate = find_lowest_num_a(stacks);
	while (ordinate)
	{
		rotate(stacks, 'a');
		ordinate--;
	}
	// Now we can start looking for the correct position of the number from stack_b to a.
	free(total_moves);
}

int	get_abs(long long int num)
{
	if (num < 0)
		return (num *= -1);
	return (num);
}

int	find_lowest_num_a(t_stack *stacks)
{
	int	i;
	int	lowest;
	int	index;
	int	to_check;

	i = 0;
	lowest = (stacks->a)[0];
	index = 0;
	while (i < stacks->n_numbers_a)
	{
		to_check = (stacks->a)[i];
		if (to_check < lowest)
		{
			lowest = to_check;
			index = i;
		}
		i++;
	}
	return (index); // Index of lowest num.
}