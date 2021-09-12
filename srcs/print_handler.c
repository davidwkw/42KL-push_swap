#include "push_swap.h"

static int	check_print_combo(char *str1, char *str2)
{
	int	combo;

	combo = 0;
	if (!ft_strncmp(str1, "sa", 2) && !ft_strncmp(str2, "sb", 2))
		combo = write(1, "ss", 2);
	else if (!ft_strncmp(str1, "ra", 2) && !ft_strncmp(str2, "rb", 2))
		combo = write(1, "rr", 2);
	else if (!ft_strncmp(str1, "rra", 3) && !ft_strncmp(str2, "rrb", 3))
		combo = write(1, "rrr", 3);
	else if (!ft_strncmp(str2, "sa", 2) && !ft_strncmp(str1, "sb", 2))
		combo = write(1, "ss", 2);
	else if (!ft_strncmp(str2, "ra", 2) && !ft_strncmp(str1, "rb", 2))
		combo = write(1, "rr", 2);
	else if (!ft_strncmp(str2, "rra", 3) && !ft_strncmp(str1, "rrb", 3))
		combo = write(1, "rrr", 3);
	return (combo);
}

static int	print_step(char *str1, char *str2)
{
	int	combo;

	combo = check_print_combo(str1, str2);
	if (!combo)
		ft_putstr_fd(str1, 1);
	ft_putchar_fd('\n', 1);
	return (combo);
}

static void	flush_printarr(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		ft_putstr_fd(strs[i], 1);
		ft_putchar_fd('\n', 1);
		free(strs[i++]);
	}
}

void	print_handler(char *str)
{
	int				i;
	int				combo;
	static char		*strs[3] = {NULL, NULL, NULL};

	i = arr_len(strs);
	if (!str)
		flush_printarr(strs);
	else if (str && i != 2)
	{
		strs[i++] = ft_strdup(str);
		if (i == 2)
		{
			combo = print_step(strs[0], strs[1]);
			free(strs[0]);
			if (combo)
				strs[0] = NULL;
			else
				strs[0] = ft_strdup(strs[1]);
			free(strs[1]);
			strs[1] = NULL;
		}
	}
}
