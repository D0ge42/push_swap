/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:10:18 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/29 20:19:41 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		num_rotation_b(t_stack *stacks, int index);
int		num_rotation_a(t_stack *stacks, int index);
void	move_parser(t_stack *stacks, int *total_moves, int rot_a, int rot_b);
void	find_optimal_move(t_stack *stacks, int *total_moves, int rot_a,
			int rot_b);

/*Core of the algorithm.
For more than 5 numbers it keeps the biggest,smallest and a random number.
Total moves array will be filled thanks to move parser. It will be filled
with the total number of moves.
We'll then filter the array and each best move thanks to find_optimal_move
Finally we'll push and ordinate the final stack in ascending order.*/

void	algorithm(t_stack *stacks)
{
	int	*total_moves;
	int	i;

	handle_push(stacks);
	total_moves = malloc(sizeof(int) * stacks->n_numbers_b);
	sort_stack_a(stacks);
	i = stacks->n_numbers_b;
	while (i--)
	{
		move_parser(stacks, total_moves, 0, 0);
		find_optimal_move(stacks, total_moves, 0, 0);
		push(stacks, 'a');
	}
	ordinate_stack(stacks);
	free(total_moves);
}

/*Move parser will get the minimum value 
out of the absolute value of rot_a and rot_b.
These are basically the rotations we've to do on each stack
before pushing the optimal number. It will get the minimum out of the two.
i.e -> rot_a = 5 rot_b = 3 --> common rotations = 3 + 2 for A.
That means we can do 3 rr and 2 ra = 5 moves.
Without this moves would be 8. */

void	move_parser(t_stack *stacks, int *total_moves, int rot_a, int rot_b)
{
	int	i;
	int	common_rrrotation;
	int	residual_a;
	int	residual_b;

	rot_a = 0;
	rot_b = 0;
	i = 0;
	while (i < stacks->n_numbers_b)
	{
		rot_a = num_rotation_a(stacks, i);
		rot_b = num_rotation_b(stacks, i);
		if ((rot_a < 0 && rot_b < 0) || (rot_a > 0 && rot_b > 0))
		{
			common_rrrotation = min(get_abs(rot_a), get_abs(rot_b));
			residual_a = get_abs(rot_a) - common_rrrotation;
			residual_b = get_abs(rot_b) - common_rrrotation;
			total_moves[i] = common_rrrotation + residual_a + residual_b;
		}
		else
			total_moves[i] = get_abs(rot_a) + get_abs(rot_b);
		i++;
	}
}

/*Since move parser just makes the sum of common_rotations+rot_a or b
I made a second function to filter the total_moves array.
With these function we'll be able to retrieve the correct number of moves for
each stack by checking if both are negatives/positives etc. */

void	find_optimal_move(t_stack *stacks, int *total_moves, int rot_a,
		int rot_b)
{
	int	common_rrrotation;
	int	index;

	common_rrrotation = 0;
	index = find_smallest_n_of_moves(stacks, total_moves);
	rot_a = num_rotation_a(stacks, index);
	rot_b = num_rotation_b(stacks, index);
	if (rot_a < 0 && rot_b < 0)
		do_rrotations(stacks, common_rrrotation, rot_a, rot_b);
	else if (rot_a > 0 && rot_b > 0)
		do_rotations(stacks, common_rrrotation, rot_a, rot_b);
	else if (rot_a >= 0 && rot_b <= 0)
		rotate_a_and_b(stacks, rot_a, rot_b);
	else if (rot_a <= 0 && rot_b >= 0)
		rotate_a_and_b(stacks, rot_a, rot_b);
}

/*Function to retrieve index of the number to rotate in b.
It's index will be the rotations we need to bring it on top.*/

int	num_rotation_b(t_stack *stacks, int index)
{
	int	rotations;

	rotations = index;
	if (rotations > get_abs(rotations - stacks->n_numbers_b))
		rotations -= stacks->n_numbers_b;
	return (rotations);
}
/*Same functionality of num_rotation_b but this time we've to confront
the number we wanna push with each number in stack_a. Since Stack_a is already 
sorted at this point, we just find for a value at index [i - 1] that is smaller
and bigger at index [i].
That does not apply if the number is the biggest or smallest.
In that case we'll only find the smallest number in the stack and that'll be it.
Last but not least, if number is over the half of the stack,
we've to do rrr instead of rr. This way we'll optimize moves.*/

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
			rotation -= stacks->n_numbers_a;
		return (rotation);
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
