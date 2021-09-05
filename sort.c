#include "push_swap.h"

static void	reverse_offset(t_list ** a, t_list **b, int offset)
{
	int	i;

	i = -1;
	while (++i < offset)
		action_dispatcher("rrb", a, b);
}

void	sort_a(t_list **a, t_list **b, int size)
{
	int median;
	int	i;

	if (size <= 3)
		return (a_base_handler(a, size));
	median = find_medval(*a, size);
	i = 0;
	while (i < size)
	{
		if (vp_to_i((*a)->content) < median) // median 213 // "788 213 1235"
		{
			action_dispatcher("pb", a, b);
			size--;
			i++;
		}
		else if (vp_to_i((ft_lstlast(*a))->content) < median)
			action_dispatcher("rra", a, b);
		else
			action_dispatcher("ra", a, b);
	}
	sort_a(a, b, size);
	sort_b(a, b, i);
}

void	sort_b(t_list **a, t_list **b, int p_size)
{
	int	median;
	int offset;

	if (p_size <= 2)
		return (b_base_handler(a, b, p_size));
	median = find_medval(*b, p_size);
	offset = 0;
	while (offset < p_size)
	{
		if (vp_to_i((*a)->content) > median)
		{
			action_dispatcher("pa", a, b);
			p_size--;
		}
		else
		{
			action_dispatcher("rb", a, b);
			offset++;
		}
	}
	reverse_offset(a, b, offset);
	sort_b(a, b, p_size);
}

void	sort_list(t_list **a, t_list **b, int size)
{
	sort_a(a, b, size);
}