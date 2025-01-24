#include "push_swap.h"

/*Function used to check if a certain char is present in a string*/

int	strchar(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}
/*Function used to free stacks when something fails.
It will free based on a flag passed as a string. */

void	free_stacks(t_stack *stacks, char *which)
{
	if (!ft_strcmp(which, "A"))
	{
		free(stacks->a);
		free(stacks);
		exit(EXIT_SUCCESS);
	}
	else if (!ft_strcmp(which, "B"))
	{
		free(stacks->b);
		free(stacks);
		exit(EXIT_SUCCESS);
	}
	else if (!ft_strcmp(which,"Struct only"))
	{
		free(stacks);
		exit(EXIT_SUCCESS);
	}
	else
	{
		free(stacks->a);
		free(stacks->b);
		free(stacks);
		exit(EXIT_SUCCESS);
	}
}
/* Used to close and free. Prints "Error" on stderror if args are not valid.
Non valid args are:
arguments aren’t integers
some arguments are bigger than an integer and/or there are duplicates. */

void	close_and_free(t_stack *stacks, char **args, char *args_free)
{
	ft_putstr_fd("Error\n", 2);
	if (!ft_strcmp(args_free, "FREE ARGS") && args)
		free_args(args);
	free_stacks(stacks, "BOTH");
}

/* Util fuction to check if a num is:
bigger than int max
lower than int min */

static int	is_int(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

/* Atoll is atoi to long long num. Similar to atoi
but it checks also if resulting num is in the integers range.
This has to be done inside the function cause the resulting number can overflow
and this can resulting in accepting args that are not valid.
It will also check if there are also non digits characters.
In case of error it will free, print "Error" and exit the main program. */

long long	ft_atoll(char *str, t_stack *stacks, char **args)
{
	long long	num;
	int			sign;
	int			i;

	if (ft_strlen(str) == 0)
		close_and_free(stacks, args, "FREE ARGS");
	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			close_and_free(stacks, args, "FREE ARGS");
		num = (num * 10) + (str[i] - '0');
		if (!is_int(num * sign))
			close_and_free(stacks, args, "FREE ARGS");
		i++;
	}
	return (num * sign);
}
