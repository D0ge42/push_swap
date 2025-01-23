#include "push_swap.h"

/*Check for duplicates inside initialized and filled stacks*/

void	check_for_duplicates(t_stack *stacks)
{
	int i = 0;
	int j = 0;
	while (i < stacks->n_numbers)
	{
		j = i + 1;
		while (j < stacks->n_numbers)
		{
			if (stacks->a[i] == stacks->a[j])
				close_and_free(stacks, NULL, "Don't free args");
			j++;
		}
        j = 0;
		i++;
	}
}