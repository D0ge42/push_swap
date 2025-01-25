/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:10:18 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/26 00:14:17 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// We first push two numbers on stack b --> 2x pb
// Now we''ll have to count all the time.
//We''ll calculate for every number how many operations needed.

//Function to check if current number is on STACK_A is going to be
//Highest in STACK_B. In this case it should be placed on top of STACK_B biggest n.

/*Will check if the highest number in STACK_B is placed on top.*/


int is_highest_on_top(t_stack *stacks)
{
    int i = 1;
    int j = 1;
    while(i < stacks->n_numbers_b)
    {
        if(!(((stacks->b)[0]) > ((stacks->b)[j])))
            return 0;
        i++;
        j++;
    }
    return 1;
}

/*If the number we push is gonna be the new smallest/Biggest it has to be placed
on top of biggest num in stack_b*/

int is_topush_biggest(t_stack *stacks)
{
    long long num_to_push = (stacks->a)[0];
    int i = 0;
    while(i < stacks->n_numbers_b)
    {
        if(!(num_to_push > (stacks->b)[i]))
            return 0;
        i++;
    }
    return 1;
}
int is_topush_smallest(t_stack *stacks)
{
    long long num_to_push = (stacks->a)[0];
    int i = 0;
    while(i < stacks->n_numbers_b)
    {
        if(!(num_to_push < (stacks->b)[i]))
            return 0;
        i++;
    }
    return 1;
}

/*If the number we've to push is not gonna be biggest nor smallest, we've to find
the right place for him and count the moves we need.*/

int find_num_position(t_stack *stacks)
{
    int num_to_push = (stacks->a)[0];
    long long int difference[stacks->n_numbers_b];
    long long int smallest_difference = 0;
    int index = 0;
    int i = 0;    
    //If number is not gonna be the biggest or lowest, we've to place it appropriately.
    //We store differences in an lli array.
    if((is_topush_biggest(stacks) || is_topush_smallest(stacks))
    && is_highest_on_top(stacks))
        return 0;
    while (i < stacks->n_numbers_b)
    {

            difference[i] = num_to_push - (stacks->b)[i];
            if(difference[i] < 0)
                difference[i]*=-1;
            i++;
    }
    i = 0;
    smallest_difference = difference[0];
    while(i < stacks->n_numbers_b)
    {
            if(difference[i] <= smallest_difference)
            {
                smallest_difference = difference[i];
                index = i;
            }
        i++;
    }
    return index;
}



// void find_lowest_moves(t_stack *stacks)
// {
//     int moves[stacks->n_numbers_a];
//     int i = 0;
//     while(i < stacks->n_numbers_a)
//     {
//         moves[i] = //Numbers of moves;
//     }
//     //Find lowest number inside moves[i] 
//     // --> its index will be the index of the number to push.
// }
