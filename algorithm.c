/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:10:18 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/26 21:53:56 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// We first push two numbers on stack b --> 2x pb
// Now we''ll have to count all the time.
//We''ll calculate for every number how many operations needed.

//Function to check if current number is on STACK_A is going to be
//Highest in STACK_B. In this case it should be placed on top of STACK_B biggest n.

/*Will check if the highest number in STACK_B is placed on top.*/
void sort_stack_a(t_stack *stacks);
int num_rotation_b(t_stack *stacks);
int num_rotation_a(t_stack *stacks, int index);
int find_lowest_num_a(t_stack *stacks);


int is_highest_on_top(t_stack *stacks)
{
    int i = 1;
    long long int num1 = (stacks->b)[0];
    while(i < stacks->n_numbers_b)
    {
        long long int num_to_check = (stacks->b)[i];
        if (num1 < num_to_check)
        {
            ft_printf("Biggest number is not on top\n");
            return 0;
        }
        i++;
    }
    ft_printf("Biggest number is on top\n");
    return 1;
}


int is_topush_biggest(t_stack *stacks, int index)
{
    long long num_to_push = (stacks->b)[index];
    int i = 0;
    while(i < stacks->n_numbers_a)
    {
        if(!(num_to_push > (stacks->a)[i]))
            return 0;
        i++;
    }
    return 1;
}
int is_topush_smallest(t_stack *stacks, int index)
{
    long long num_to_push = (stacks->b)[index];
    int i = 0;
    while(i < stacks->n_numbers_a)
    {
        if(!(num_to_push < (stacks->a)[i]))
            return 0;
        i++;
    }
    return 1;
}

void find_common_rotation(t_stack *stacks)
{
    int num_rot_b = num_rotation_b(stacks);
    int num_rot_a = num_rotation_a(stacks, num_rot_b);
    //Common rotations
    int rr = min(num_rot_a,num_rot_b);
    while(rr--)
        rotate(stacks,BOTH);

    // Calculate and print remaining rotations
    int remaining_rot_a = num_rot_a - min(num_rot_a, num_rot_b);
    int remaining_rot_b = num_rot_b - min(num_rot_a, num_rot_b);
    while (remaining_rot_a--)
        rotate(stacks, 'a');
    while (remaining_rot_b--)
        rotate(stacks, 'b');
}

void algorithm(t_stack *stacks)
{
    //We push until 3 numbers are left in the stack.
    while(stacks->n_numbers_a > 3)
        push(stacks,'b');
    //Once we've pushed all the numbers but 3 in b, it's time to sort stack A.
    sort_stack_a(stacks);
    int i = stacks->n_numbers_b;
    while(i--)
    {
        find_common_rotation(stacks);
        push(stacks,'a');
    }
    int ordinate = find_lowest_num_a(stacks);
    while (ordinate)
    {
        rotate(stacks,'a');
        ordinate--;
    }
    //Now we can start looking for the correct position of the number from stack_b to a.
}

int num_rotation_a(t_stack *stacks, int index)
{
    long long int num  = (stacks->b)[index];
    int i  = 1;
    if (is_topush_smallest(stacks,index))
        return 0;
    if (is_topush_biggest(stacks,index))
    {
        return (find_lowest_num_a(stacks));
        // if (index > stacks->n_numbers_a / 2)
        // {
        //     //Rra instead of RA.
        // }
    }
    while(i < stacks->n_numbers_a)
    {
        if(num > (stacks->a)[i - 1] && num < (stacks->a)[i])
            break;
        i++;
    }
    return i ;
}




int num_rotation_b(t_stack *stacks)
{
    int i = 1;
    int lowest = (stacks->b)[0];
    int rot_b = 0;
    while(i < stacks->n_numbers_b)
    {
        int to_check = (stacks->b)[i];
        if(to_check < lowest)
        {
            lowest = to_check;
            rot_b = i;
        }
        i++;
    }
    return rot_b;
}

int find_lowest_num_a(t_stack *stacks)
{
    int i = 1;
    int lowest = (stacks->a)[0];
    int index = 0;
    while(i < stacks->n_numbers_a)
    {
        int to_check = (stacks->a)[i];
        if(to_check < lowest)
        {
            lowest = to_check;
            index = i;
        }
        i++;
    }
    return index; //Index of lowest num.
}

void sort_stack_a(t_stack *stacks)
{
    if (stacks->a[0] > stacks->a[1] && stacks->a[0] > stacks->a[2])
        rotate(stacks, 'a'); 
    else if (stacks->a[1] > stacks->a[0] && stacks->a[1] > stacks->a[2])
        rrotate(stacks, 'a');
    if (stacks->a[0] > stacks->a[1])
        swap(stacks, 'a');
}