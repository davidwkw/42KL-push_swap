#include "push_Swap.h"

static int	print_step(char *str1, char *str2)
{
	if (!ft_strncmp(str1, "sa", 2) && !ft_strncmp(str2, "sb", 2))
		return (write(1, "ss", 2));
	else if (!ft_strncmp(str1, "ra", 2) && !ft_strncmp(str2, "rb", 2))
		return (write(1, "rr", 2));
	else if (!ft_strncmp(str1, "rra", 3) && !ft_strncmp(str2, "rrb", 3))
		return (write(1, "rrr", 3));
	else
	{
		ft_putstr_fd(str1, 1);
		return (0);
	}
}

void	print_handler(char *str)
{
	int		i;
	int		combo;
	static char		*strs[3] = {NULL, NULL, NULL};

	i = 0;
	while (strs[i])
		i++;
	if (!str && i == 1)
	{
		ft_putstr_fd(strs[0], 1);
		free(strs[0]);
	}
	if (i != 2)
	{
		str[i] = ft_strdup(str);
		return ;
	}
	combo = print_step(strs[0], strs[1]); 
	free(strs[0]);
	if (combo)
		strs[0] = NULL;
	else
		strs[0] = strs[1];
	free(strs[1]);
	strs[1] = NULL;
}
