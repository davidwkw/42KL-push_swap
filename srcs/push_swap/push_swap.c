#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*list;
	t_list	*stack_a;
	t_list	*stack_b;
	int		total_size;

	if (argc > 1)
	{
		init_structs(&stack_a, &stack_b);
		total_size = argc - 1;
		list = validate_int_args(&total_size, (argv + 1));
		fill_stack(&stack_a, total_size, list);
		sort_a(&stack_a, &stack_b, total_size);
		print_handler(NULL);
		clear_list(&stack_a);
		free(list);
	}
	return (0);
}
