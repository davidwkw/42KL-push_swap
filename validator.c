#include <limits.h>
#include "push_swap.h"

static void	is_arrint(int arr_c, char **s)
{
	unsigned int	i;

	i = 0;
	while (i < arr_c)
	{
		while (*s[i])
		{
			if (*s[i] == '-')
				s[i]++;
			if (!ft_isdigit(*s[i]))
				error_handler("Error");
			s[i]++;
		}
		i++;
	}
}

static int	*atoi_intl(unsigned int arrc, char *arr[])
{
	unsigned int	i;
	int				*list;

	list = malloc(sizeof(int) * (arrc + 1));
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

static int	check_arrduplimits(unsigned int arrc, int *list)
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
		while (list[j])
		{
			if (list[i] == list[j++])
			{
				free(list);
				error_handler("Error");
			}
		}
	}
}

static unsigned int arr_len(char *arr[])
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	*validate_int_args(int *arrc, char *arr[])
{
	int	*list;

	if (*arrc == 2)
	{
		arr = ft_split(arr[1], ' ');
		*arrc = arr_len(arr);
	}
	else
		*arrc -= 1;
	is_arrint(*arrc, arr);
	list = atoi_intl(*arrc, arr);
	if (!list)
		error_handler("Error");
	check_arrduplimits(*arrc, list);
	return (list);
}