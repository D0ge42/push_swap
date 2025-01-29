/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:25:19 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/29 14:18:50 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Check for duplicates inside initialized and filled stacks*/

void	check_for_duplicates(t_stack *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stacks->n_numbers_a)
	{
		j = i + 1;
		while (j < stacks->n_numbers_a)
		{
			if (stacks->a[i] == stacks->a[j])
				close_and_free(stacks, NULL, "Don't free args");
			j++;
		}
		j = 0;
		i++;
	}
}
