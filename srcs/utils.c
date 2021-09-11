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

void	free_nested_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

int	arr_len(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	clear_list(t_list **lst)
{
	t_list	*next;

	if (*lst)
	{
		while (*lst)
		{
			next = (*lst)->next;
			free(*lst);
			*lst = next;
		}
		*lst = NULL;
	}
}
