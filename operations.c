/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:40:40 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/24 12:31:56 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void push_a(t_stack *stacks)
{
    int i = 1;
    int j = 0;
    long long int tmp_arrayA[stacks->n_numbers_a + 1];
    long long int tmp_arrayB[stacks->n_numbers_a + 1];


    tmp_arrayA[0] = (stacks->b)[0];
    //Salvo tutti i valori di B in un temp array a partire da i + 1;
    while(j < (stacks->n_numbers_b))
        tmp_arrayB[j++] = (stacks->b)[i++];
    //Remove shifted element from b.
    free(stacks->b);
    stacks->n_numbers_b-=1;
    stacks->b = malloc(sizeof(long long int ) * (stacks->n_numbers_b));
    //Now we've to copy from tmp_arrayB+1 into the newly allocated stackB
    j = 0;
    while(j < (stacks->n_numbers_b))
    {
        (stacks->b)[j] = tmp_arrayB[j];
        j++;
    }
    //Once that is done we can push the new
    j = 0;
    i = 1;
    while(j < (stacks->n_numbers_a))
        tmp_arrayA[i++] = (stacks->a)[j++];
    
    free(stacks->a);
    stacks->n_numbers_a+=1;
    (stacks->a) = malloc(sizeof(long long int) * (stacks->n_numbers_a));
    i = 0;
    while(i < stacks->n_numbers_a)
    {
        (stacks->a)[i] = tmp_arrayA[i];
        i++;
    }
    i = 0;
    while(i < stacks->n_numbers_a)
    {
        ft_printf("Stacks A[%i] = %i\n", i,(stacks->a)[i]);
        i++;
    }
}

void push_b(t_stack *stacks)
{
    int i = 1;
    int j = 0;
    long long int tmp_array[stacks->n_numbers_b + 1];

    tmp_array[0] = (stacks->a)[0];
    while(j < (stacks->n_numbers_b))
        tmp_array[i++] = (stacks->b)[j++];
    
    free(stacks->b);
    (stacks->b) = malloc(sizeof(long long int) * (stacks->n_numbers_b + 1));
    i = 0;
    while(i < stacks->n_numbers_b + 1)
    {
        (stacks->b)[i] = tmp_array[i];
        i++;
    }
    i = 0;
    while(i < stacks->n_numbers_b + 1)
    {
        ft_printf("Stacks B[%i] = %i\n", i,(stacks->b)[i]);
        i++;
    }
    stacks->n_numbers_b+=1;
}


void    push(t_stack *stacks, char which)
{
    
    if (stacks->n_numbers_b >= 1 && which == 'a')
    {
        push_a(stacks); 
        ft_printf("pa\n");
    }
    else if (stacks->n_numbers_a > 1 && which == 'b')
    {
        push_b(stacks);
        ft_printf("pb\n");   
    }
}

void	swap_ss(t_stack *stacks)
{
	int	tmpA;
	int	tmpB;

	tmpA = 0;
	tmpB = 0;
	if ((stacks->n_numbers_a) > 1 && (stacks->n_numbers_b) > 1)
	{
		tmpA = (stacks->a)[0];
		(stacks->a)[0] = (stacks->a)[1];
		(stacks->a)[1] = tmpA;
		tmpB = (stacks->b)[0];
		(stacks->b)[0] = (stacks->b)[1];
		(stacks->b)[1] = tmpB;
		ft_printf("ss\n", 1);
	}
}

void	swap(t_stack *stacks, char which)
{
	int	tmpA;
	int	tmpB;

	tmpA = 0;
	tmpB = 0;
	if (which == 'a')
	{
		if ((stacks->n_numbers_a) > 1)
		{
			tmpA = (stacks->a)[0];
			(stacks->a)[0] = (stacks->a)[1];
			(stacks->a)[1] = tmpA;
			ft_printf("sa\n", 1);
		}
	}
	else if (which == 'b')
	{
		if ((stacks->n_numbers_b) > 1)
		{
			tmpB = (stacks->b)[0];
			(stacks->b)[0] = (stacks->b)[1];
			(stacks->b)[1] = tmpB;
			ft_printf("sb\n", 1);
		}
	}
}
