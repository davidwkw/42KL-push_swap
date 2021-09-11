#include "push_swap.h"

static int	combo_check(char *action, t_list **a, t_list **b)
{
	int	success;

	success = 0;
	if (!ft_strncmp(action, "ss", 2))
		success = combo_swap(a, b);
	else if (!ft_strncmp(action, "rr", 2))
		success = combo_rotate(a, b);
	else if (!ft_strncmp(action, "rrr", 3))
		success = combo_reverse_rotate(a, b);
	return (success);
}

int	action_handler(char *action, t_list **a, t_list **b)
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
	else
		success = combo_check(action, a, b);
	return (success);
}

void	action_dispatcher(char *action, t_list **a, t_list **b)
{
	char	**steps;
	int		i;
	int		success;

	steps = ft_split(action, ' ');
	i = 0;
	while (steps[i])
	{
		success = action_handler(steps[i], a, b);
		if (success)
			print_handler(steps[i]);
		i++;
	}
	free_nested_arr(steps);
}
