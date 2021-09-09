#include "checker.h"

int	is_valid_step(char *step)
{
	if (!ft_strncmp(step, "sa", 2))
		return (1);
	else if (!ft_strncmp(step, "sb", 2))
		return (1);
	else if (!ft_strncmp(step, "pa", 2))
		return (1);
	else if (!ft_strncmp(step, "pb", 2))
		return (1);
	else if (!ft_strncmp(step, "ra", 2))
		return (1);
	else if (!ft_strncmp(step, "rb", 2))
		return (1);
	else if (!ft_strncmp(step, "rra", 3))
		return (1);
	else if (!ft_strncmp(step, "rrb", 3))
		return (1);
	return (0);
}

void	execute_step(char *step, t_list **a, t_list **b)
{
	if (!is_valid_step(step))
		error_handler("KO\n");
	action_dispatcher(step, a, b);
}

int	main(int argc, char **argv)
{
	int		*list;
	char	*step;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc > 1)
	{
		init_structs(&stack_a, &stack_b);
		list = validate_int_args(&argc, (argv + 1));
		fill_stack(&stack_a, argc, list);
		while (get_next_line(0, &step))
			execute_step(step, &stack_a, &stack_b);
		if (!is_a_sorted(stack_a, ft_lstsize(stack_a)) && ft_lstsize(stack_b))
			error_handler("KO\n");
		free(list);
		ft_putstr_fd("OK\n" ,1);
	}
	return (0);
}