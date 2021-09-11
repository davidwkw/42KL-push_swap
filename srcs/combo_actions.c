#include "push_swap.h"

int	combo_swap(t_list **a, t_list **b)
{
	return (swap(a)	&& swap(b));	
}

int	combo_rotate(t_list **a, t_list **b)
{
	return (rotate(a) && rotate(b));
}

int	combo_reverse_rotate(t_list **a, t_list **b)
{
	return (reverse_rotate(a) && reverse_rotate(b));
}
