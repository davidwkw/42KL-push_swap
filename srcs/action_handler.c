#include "push_swap.h"

static void	action_handler(char *action, t_list **a, t_list **b)
{
	int	success;

	success = 0;
	if (!ft_strncmp(action, "sa", 2))
		success = swap(a);
	else if (!ft_strncmp(action, "sb", 2))
		success = swap(b);
	else if (!ft_strncmp(action, "pa", 2))
		success = push(b, a);
	else if (!ft_strncmp(action, "pb", 2))
		success = push(a, b);
	else if (!ft_strncmp(action, "ra", 2))
		success = rotate(a);
	else if (!ft_strncmp(action, "rb", 2))
		success = rotate(b);
	else if (!ft_strncmp(action, "rra", 3))
		success = reverse_rotate(a);
	else if (!ft_strncmp(action, "rrb", 3))
		success = reverse_rotate(b);
	if (success)
		print_handler(action);
}

void	action_dispatcher(char *action, t_list **a, t_list **b)
{
	char	**steps;
	int		i;

	steps = ft_split(action, ' ');
	i = 0;
	while (steps[i])
		action_handler(steps[i++], a, b);
}