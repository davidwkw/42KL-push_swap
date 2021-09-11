#include <limits.h>
#include "push_swap.h"

static void	is_arrint(int arr_c, char **s)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_c)
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '-')
				j++;
			if (!ft_isdigit(s[i][j]))
				error_handler("Error");
			j++;
		}
		i++;
	}
}

static int	*atoi_intl(unsigned int arrc, char *arr[])
{
	unsigned int	i;
	int				*list;

	list = malloc(sizeof(int) * (arrc));
	i = 0;
	if (list)
	{
		while (i < arrc)
		{
			list[i] = ft_atoi(arr[i]);
			i++;
		}
	}
	return (list);
}

static void	check_arrduplimits(unsigned int arrc, int *list)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < arrc)
	{
		if (list[i] >= INT_MAX || list[i] <= INT_MIN)
		{
			free(list);
			error_handler("Error");
		}
		j = i + 1;
		while (j < arrc)
		{
			if (list[i] == list[j])
			{
				free(list);
				error_handler("Error");
			}
			j++;
		}
		i++;
	}
}

static char	**duplicate_arr(char **arr, int arrc)
{
	char	**arr_cpy;
	int		i;

	arr_cpy = malloc(sizeof(char *) * (arrc + 1));
	i = -1;
	while (arr[++i])
		arr_cpy[i] = ft_strdup(arr[i]);
	arr_cpy[i] = NULL;
	return (arr_cpy);
}

int	*validate_int_args(int *arrc, char **arr)
{
	int		*list;

	if (*arrc == 1)
		arr = ft_split(*arr, ' ');
	else
		arr = duplicate_arr(arr, *arrc);
	*arrc = arr_len(arr);
	is_arrint(*arrc, arr);
	list = atoi_intl(*arrc, arr);
	free_nested_arr(arr);
	if (!list)
		error_handler("Error");
	check_arrduplimits(*arrc, list);
	return (list);
}
