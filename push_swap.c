/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:22:26 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/26 00:12:39 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Ac - 1 is gonna be the number of numbers to sort.
// We've to print the name of operations done. i.e rra pa pb ss etc
// Sort in ascending order, smallest to greatest
// We've two stacks. a and b.
// Stack a contains a random amount of negative/positive numbers. No duplicates.
// Stack b is empty.
// no more than 5500 operations for 500 random numbers.

static void	fill_stacks(t_stack *stacks, int ac, char **av);

#include <stdio.h>

void print_stacks(t_stack *stacks) 
{
    int max_size = max(stacks->n_numbers_a,stacks->n_numbers_b);
	int i = 0;
	
    printf("-------------------------------------\n");
    printf("   STACK A                   STACK B \n");
    printf("-------------------------------------\n");

    while(i < max_size) 
	{
        if (i < stacks->n_numbers_a)
            ft_printf("    A[%i]: %lli", i, (stacks->a)[i]);
		else 
            ft_printf("              "); // Empty space for Stack A
        ft_printf("          "); // Space between stacks
        if (i < stacks->n_numbers_b) 
            ft_printf("  B[%d]: %lld", i, (stacks->b)[i]);
        ft_printf("\n");
		i++;
    }
    printf("-------------------------------------\n");
}


/*Main function:
allocates memory for a stack structure.
checks for eventual errors inside the stack, duplicates etc
free everything that was previously allocated. */

int	main(int ac, char **av)
{
	t_stack	*stacks;
	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		return (1);
	if (ac == 1)
		free_stacks(stacks, "Struct only");
	// Initialize stack_a with numbers.
	fill_stacks(stacks, ac, av);
	check_for_duplicates(stacks);
	push_b(stacks);
	push_b(stacks);
	push_b(stacks);
	push_b(stacks);
	int i = find_num_position(stacks);
	ft_printf("Rotation to do %i\n",i);
	while(i > 0)
	{
		rotate(stacks,'b');
		i--;
	}
	push_b(stacks);
	print_stacks(stacks);
	// Function to sort them. It has to take both array. Print Operations on stdout.
	// Free everything that was previously allocated
	free_stacks(stacks, "BOTH");
}

/* Function responsible for filling and initializing both stack a and b.
Program will accept numbers as single arguments strings "1 2 3".
Program will accept numbers as single arguments 1 2 3. */

void	fill_stacks(t_stack *stacks, int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**args;

	k = 0;
	i = 1;
	j = 0;
	args = NULL;
	stacks->n_numbers_a = count_nums(ac, av);
	stacks->n_numbers_b = 0;
	stacks->a = malloc(sizeof(long long int) * (stacks->n_numbers_a));
	stacks->b = malloc(sizeof(long long int) * (stacks->n_numbers_a));
	check_malloc_fail(stacks);
	while (i < ac)
	{
		if (strchar(' ', av[i]))
		{
			args = ft_split(av[i], ' ');
			while (args[k])
				(stacks->a)[j++] = ft_atoll(args[k++], stacks, args);
		}
		else
			(stacks->a)[j++] = ft_atoll(av[i], stacks, args);
		i++;
	}
	if (args)
		free_args(args);
}
