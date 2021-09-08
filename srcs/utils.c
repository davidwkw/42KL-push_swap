#include "push_swap.h"

void	error_handler(char *error)
{
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(1);
}

int	vp_to_i(void *ptr)
{
	return (*((int *)ptr));
}

int	arr_len(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
