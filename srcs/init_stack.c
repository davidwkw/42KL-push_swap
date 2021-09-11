#include "push_swap.h"

void	init_structs(t_list **a_head, t_list **b_head)
{
	*a_head = NULL;
	*b_head = NULL;
}

void	fill_stack(t_list **stack_a, int argc, int *list)
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
