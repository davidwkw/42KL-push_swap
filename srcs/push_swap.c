#include "push_swap.h"

static void	init_structs(t_list **a_head, t_list **b_head)
{
	*a_head = NULL;
	*b_head = NULL;
}

static void	fill_stack(t_list **stack_a, int argc, int *list)
{
	int		i;
	t_list	*node;

	i = 0;
	while (i < argc)
	{
		node = ft_lstnew(&list[i]);
		if (!node)
			error_handler("Error");
		ft_lstadd_back(stack_a, node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		*list;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc > 1)
	{
		init_structs(&stack_a, &stack_b);
		list = validate_int_args(&argc, (argv + 1));
		fill_stack(&stack_a, argc, list);
		sort_a(&stack_a, &stack_b, argc);
		print_handler(NULL);
		free(list);
	}
	return (0);
}
