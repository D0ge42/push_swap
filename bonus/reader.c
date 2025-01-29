/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:32:22 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/29 23:06:18 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*gnl_checker(int fd)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;
    char    *line;

	i = 0;
	r = 0;
	buffer = (char *)malloc(1000000);
	if (!buffer)
		return (NULL);
	r = read(fd, &c, 1);
    if (!r)
    {
        free(buffer);
        return NULL;
    }
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(fd, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	line = buffer;
	return (line);
}

int	read_from_stdin(t_stack *stacks)
{
	char	*operation;
	
    operation = NULL;
	while (1)
	{
		operation = gnl_checker(0);
		if (!operation)
        {
            free(operation);
			break ;
        }
		if (!do_operations(operation, stacks))
        {
		    free(operation);
			free_stacks(stacks, "BOTH");
        }
		free(operation);
	}
	return (1);
}

int	do_operations(char *operation, t_stack *stacks)
{
	if (!ft_strcmp(operation, "sa\n"))
		swap(stacks, 'a');
	else if (!ft_strcmp(operation, "sb\n"))
		swap(stacks, 'b');
	else if (!ft_strcmp(operation, "ss\n"))
		swap(stacks, BOTH);
	else if (!ft_strcmp(operation, "pa\n"))
		push(stacks, 'a');
	else if (!ft_strcmp(operation, "pb\n"))
		push(stacks, 'b');
	else if (!ft_strcmp(operation, "ra\n"))
		rotate(stacks, 'a');
	else if (!ft_strcmp(operation, "rb\n"))
		rotate(stacks, 'b');
	else if (!ft_strcmp(operation, "rr\n"))
		rotate(stacks, BOTH);
	else if (!ft_strcmp(operation, "rra\n"))
		rrotate(stacks, 'a');
	else if (!ft_strcmp(operation, "rrb\n"))
		rrotate(stacks, 'b');
	else if (!ft_strcmp(operation, "rrr\n"))
		rrotate(stacks, BOTH);
	else
		return (0);
	return (1);
}