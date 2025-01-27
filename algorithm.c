/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:10:18 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/27 18:30:21 by lonulli          ###   ########.fr       */
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

int	is_highest_on_top(t_stack *stacks)
{
	int				i;
	long long int	num1;
	long long int	num_to_check;

	i = 1;
	num1 = (stacks->b)[0];
	while (i < stacks->n_numbers_b)
	{
		num_to_check = (stacks->b)[i];
		if (num1 < num_to_check)
		{
			ft_printf("Biggest number is not on top\n");
			return (0);
		}
		i++;
	}
	ft_printf("Biggest number is on top\n");
	return (1);
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

// void	find_optimal_move(t_stack *stacks)
// {

// 	// Optimal move is the one that takes less rotations for both A and B before being pushed.
// 	// For each number/index we''ll assign a value which will be n of moves
// 	// Optimal moves of a number will be rotations for a + rotations for b.
//     //I first calculate moves and store them inside an array.

//     //Moves will be moves rotations of a to put number in the right spot
//     //Plus Moves needed to move the numbers on top of the stack.

//     //Then i find the number to push thanks to the stored index.
// }

int	num_rotation_b(t_stack *stacks, int index)
{
	int	rotations;

	rotations = index;
	if (rotations > get_abs(rotations - stacks->n_numbers_b))
	{
		rotations -= stacks->n_numbers_b;
	}
	return (rotations);
}

int	num_rotation_a(t_stack *stacks, int index)
{
	long long int	num;
	int				i;
	int				rotation;

	num = (stacks->b)[index];
	i = 1;
	if (is_topush_smallest(stacks, index))
		return (0);
	if (is_topush_biggest(stacks, index))
	{
		rotation = (find_lowest_num_a(stacks));
		if (rotation > get_abs(i - stacks->n_numbers_a))
		{
		    rotation -= stacks->n_numbers_a;
		    return (rotation);
		}
	}
	while (i < stacks->n_numbers_a)
	{
		if (num > (stacks->a)[i - 1] && num < (stacks->a)[i])
			break ;
		i++;
	}
	if (i < get_abs(i - stacks->n_numbers_a))
	{
		i = i - stacks->n_numbers_a;
	}
	return (i);
}

void move_parser(t_stack *stacks) 
{
	int	i;
	i = 0;
	while (i < stacks->n_numbers_b)
	{
		int rot_a = num_rotation_a(stacks, i);
		int rot_b = num_rotation_b(stacks, i);
		if (rot_a < 0 && rot_b < 0)
		{
			//There are common RRR rotations
			
		}
	}
	// if (ft_strcmp(str, "RRR"))
	// {

	// }
}

void	algorithm(t_stack *stacks)
{
	int	i;

	// int	ordinate;
	i = 0;
	// This array will be filled with the total moves required for each number.
	// We push until 3 numbers are left in the stack.
	while (stacks->n_numbers_a > 3)
		push(stacks, 'b');
	int *total_moves = malloc(sizeof(int ) * stacks->n_numbers_b);
	// Once we've pushed all the numbers but 3 in b, it's time to sort stack A.
	sort_stack_a(stacks);
	while (i < stacks->n_numbers_b)
	{
		ft_printf("Num of Rotation for a = %i\n",num_rotation_a(stacks,i));
		ft_printf("Num of Rotation for b = %i\n",num_rotation_b(stacks,i));
		//total_moves[i] = num_rotation_a(stacks, i, &reverse_flagA) + num_rotation_b(stacks, i, &reverse_flagB);
		// ft_printf("\n\n");
		i++;
	}

	// i = stacks->n_numbers_b;
	// while (i--)
	// {
	// 	// Calculate number that takes less moves.
	// 	// Function that will calculate optimal number to push from B to A
	// 	print_stacks(stacks);
	// }
	// ordinate = find_lowest_num_a(stacks);
	// while (ordinate)
	// {
	// 	rotate(stacks, 'a');
	// 	ordinate--;
	// }
	// Now we can start looking for the correct position of the number from stack_b to a.
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

	i = 1;
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

void	sort_stack_a(t_stack *stacks)
{
	if (stacks->a[0] > stacks->a[1] && stacks->a[0] > stacks->a[2])
		rotate(stacks, 'a');
	else if (stacks->a[1] > stacks->a[0] && stacks->a[1] > stacks->a[2])
		rrotate(stacks, 'a');
	if (stacks->a[0] > stacks->a[1])
		swap(stacks, 'a');
}