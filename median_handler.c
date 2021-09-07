#include "push_swap.h"

int	find_medval(t_list *stack, int size)
{
	int median_i;
	int i;
	int	median;

	median_i = size / 2 + size % 2;
	i = -1;
	median = stack->content;
	while (++i < median_i)
	{
		if (stack->content > median)
			median = stack->content;
		stack = stack->next;
	}
	while (stack && median_i < size)
	{
		if (stack->content < median)
			median = stack->content;
		stack = stack->next;
		median_i++;
	}
	return (median);
}
