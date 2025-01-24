#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				n_numbers_a;
	int				n_numbers_b;
	long long int	*a;
	long long int	*b;
}					t_stack;

void				check_for_duplicates(t_stack *stacks);
long long			ft_atoll(char *str, t_stack *stacks, char **args);
void				close_and_free(t_stack *stacks, char **args,
						char *args_free);
void				free_stacks(t_stack *stacks, char *which);
void				free_stacks(t_stack *stacks, char *which);
int					strchar(char c, char *str);
void				free_args(char **args);
int					count_nums(int ac, char **av);
void				check_malloc_fail(t_stack *stacks);


/*Operations*/

void push_a(t_stack *stacks);
void push_b(t_stack *stacks);
void    push(t_stack *stacks, char which);
void	rotate_a(t_stack *stacks);
void	rotate_b(t_stack *stacks);

#endif