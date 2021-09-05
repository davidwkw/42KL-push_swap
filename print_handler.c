#include "push_Swap.h"

static int	print_step(char *str1, char *str2)
{
	if (!ft_strncmp(str1, "sa", 2) && !ft_strncmp(str2, "sb", 2))
		return (write(1, "ss\n", 3));
	else if (!ft_strncmp(str1, "ra", 2) && !ft_strncmp(str2, "rb", 2))
		return (write(1, "rr\n", 3));
	else if (!ft_strncmp(str1, "rra\n", 4) && !ft_strncmp(str2, "rrb", 3))
		return (write(1, "rrr\n", 4));
	else
	{
		ft_putstr_fd(str1, 1);
		ft_putchar_fd('\n', 1);
		return (0);
	}
}

void	print_handler(char *str)
{
	int				i;
	int				j;
	int				combo;
	static char		*strs[3] = {NULL, NULL, NULL};

	i = arr_len(strs);
	if (!str && i > 0)
	{
		j = 0;
		while (j < i) // can be replaced with while strs[j]
		{
			ft_putstr_fd(strs[j], 1);
			ft_putchar_fd('\n', 1);
			free(strs[j++]);
		}
	}
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

// void	print_handler(char *str)
// {
// 	int				i;
// 	int				j;
// 	int				combo;
// 	static char		*strs[3] = {NULL, NULL, NULL};

// 	i = arr_len(strs);
// 	if (!str && i > 0)
// 	{
// 		j = 0;
// 		while (j < i) // can be replaced with while strs[j]
// 		{
// 			ft_putstr_fd(strs[j], 1);
// 			ft_putchar_fd('\n', 1);
// 			free(strs[j]);
// 			j++;
// 		}
// 		return ;
// 	}
// 	else if (i != 2)
// 	{
// 		strs[i] = ft_strdup(str);
// 		return ;
// 	}
// 	combo = print_step(strs[0], strs[1]); 
// 	free(strs[0]);
// 	if (combo)
// 		strs[0] = NULL;
// 	else
// 		strs[0] = strs[1];
// 	free(strs[1]);
// 	strs[1] = NULL;
// }
