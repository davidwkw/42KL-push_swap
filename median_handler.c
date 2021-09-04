#include "push_swap.h"

int	find_medval(t_list *stack, int size)
{
	int median_i;
	int i;

	median_i = size / 2 ;
	i = -1;
	while (stack && ++i <= median_i)
		stack = stack->next;
	return (vp_to_i(stack->content));
}
