/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:10:18 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/25 20:09:12 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// We first push two numbers on stack b --> 2x pb
// Now we''ll have to count all the time.
//We''ll calculate for every number how many operations needed.

//Function to check if current number is on STACK_A is going to be
//Highest in STACK_B. In this case it should be placed on top of STACK_B biggest n.

//Function that will calculate opeartions for each number.

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
