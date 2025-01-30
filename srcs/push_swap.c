/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:22:26 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/30 18:21:08 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fill_stacks(t_stack *stacks, int ac, char **av);
static void	initialize(t_stack *stacks, int ac, char **av);

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
	fill_stacks(stacks, ac, av);
	check_for_duplicates(stacks);
	if (is_already_sorted(stacks))
		free_stacks(stacks, "BOTH");
	algorithm(stacks);
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
	initialize(stacks, ac, av);
	check_malloc_fail(stacks);
	while (i < ac)
	{
		k = 0;
		args = ft_split(av[i], ' ');
		if (!args[0])
			close_and_free(stacks, args, "FREE ARGS");
		while (args[k])
		{
			(stacks->a)[j++] = ft_atoll(args[k], stacks, args);
			k++;
		}
		free_args(args);
		i++;
	}
}

static void	initialize(t_stack *stacks, int ac, char **av)
{
	stacks->n_numbers_a = count_nums(ac, av);
	stacks->n_numbers_b = 0;
	stacks->a = malloc(sizeof(long long int) * (stacks->n_numbers_a));
	stacks->b = malloc(sizeof(long long int) * (stacks->n_numbers_a));
}

// void	print_stacks(t_stack *stacks)
// {
// 	int	max_size;
// 	int	i;

// 	max_size = max(stacks->n_numbers_a, stacks->n_numbers_b);
// 	i = 0;
// 	printf("-------------------------------------\n");
// 	printf("   STACK A                   STACK B \n");
// 	printf("-------------------------------------\n");
// 	while (i < max_size)
// 	{
// 		if (i < stacks->n_numbers_a)
// 			ft_printf("    A[%i]: %lli", i, (stacks->a)[i]);
// 		else
// 			ft_printf("              ");
// 		ft_printf("          ");
// 		if (i < stacks->n_numbers_b)
// 			ft_printf("  B[%i]: %lli", i, (stacks->b)[i]);
// 		ft_printf("\n");
// 		i++;
// 	}
// 	printf("-------------------------------------\n");
// }
