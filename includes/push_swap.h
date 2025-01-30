/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:26:58 by lonulli           #+#    #+#             */
/*   Updated: 2025/01/30 21:38:00 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>

# define BOTH 'x'

typedef struct s_stack
{
	int				n_numbers_a;
	int				n_numbers_b;
	int				index_max;
	int				index_min;
	int				avrg;
	long long int	*a;
	long long int	*b;
}					t_stack;

void				check_for_duplicates(t_stack *stacks);
long long			ft_atoll(char *str, t_stack *stacks, char **args);
void				close_and_free(t_stack *stacks, char **args,
						char *args_free);
void				free_stacks(t_stack *stacks, char *which);
int					strchar(char c, char *str);
void				free_args(char **args);
int					count_nums(int ac, char **av);
void				check_malloc_fail(t_stack *stacks);
void				handle_sign(char *str, int *i, int *sign);
int					is_topush_smallest(t_stack *stacks, int index);
int					is_topush_smallest(t_stack *stacks, int index);
void				sort_stack_a(t_stack *stacks);
void				find_biggest_and_lowest(t_stack *stacks);
void				handle_push(t_stack *stacks);
int					is_int(long long int num);

/*Operations*/

void				push_a(t_stack *stacks);
void				push_b(t_stack *stacks);
void				push(t_stack *stacks, char which);
void				rrotate_a(t_stack *stacks);
void				rrotate_b(t_stack *stacks);
void				rrotate(t_stack *stacks, char which);
void				rotate_a(t_stack *stacks);
void				rotate_b(t_stack *stacks);
void				rotate(t_stack *stacks, char which);
void				swap_a(t_stack *stacks);
void				swap_b(t_stack *stacks);
void				swap_ss(t_stack *stacks);
void				swap(t_stack *stacks, char which);
void				do_rrotations(t_stack *stacks, int common_rrrotation,
						int rot_a, int rot_b);
int					find_smallest_n_of_moves(t_stack *stacks, int *total_moves);
void				rotate_a_and_b(t_stack *stacks, int rot_a, int rot_b);
void				do_rotations(t_stack *stacks, int common_rrrotation,
						int rot_a, int rot_b);

int					is_topush_smallest(t_stack *stacks, int index);
int					is_topush_biggest(t_stack *stacks, int index);
void				algorithm(t_stack *stacks);
int					min(int a, int b);
void				print_stacks(t_stack *stacks);
int					get_abs(long long int a);
int					is_already_sorted(t_stack *stacks);
void				ordinate_stack(t_stack *stacks);
int					find_lowest_num_a(t_stack *stacks);

#endif