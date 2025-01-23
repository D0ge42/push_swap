#include "push_swap.h"

/*Check for duplicates inside initialized and filled stacks*/

void	check_for_duplicates(t_stack *stacks, int ac)
{
	int i = 0;
	int j = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (stacks->a[i] == stacks->a[j])
				close_and_free(stacks, NULL, "Don't free args");
			j++;
		}
		i++;
	}
}