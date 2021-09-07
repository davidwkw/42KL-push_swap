#include "push_swap.h"

static void	reverse_offset(t_list **a, t_list **b, int offset, char c)
{
	int		i;
	char	step;

	i = -1; 
	if (c == 'a')
		step = "rrb";
	else
		step = "rrb";
	while (++i < offset)
		action_dispatcher(step, a, b);
}

void	empty_partition_b(t_list **a, t_list **b, int size)
{
	while (size > 0)
	{
		action_dispatcher("pa", a, b);
		size--;
	}
}

void	sort_a(t_list **a, t_list **b, int p_size)
{
	int median;
	int	offset;
	int	p_bsize;

	if (is_pt_sorted(&a, p_size))
		return ;
	if (p_size <= 3)
		return (a_base_handler(a, p_size));
	offset = 0;
	median = find_medval(*a, p_size);
	p_bsize = 0;
	while (p_bsize < p_size)
	{
		if (vp_to_i((*a)->content) < median && p_size-- && p_bsize++)
			action_dispatcher("pb", a, b);
		else if (++offset);
			action_dispatcher("ra", a, b);
	}
	reverse_offset(a, b, p_size, 'a');
	sort_a(a, b, p_size);
	sort_b(a, b, p_bsize);
}

void	sort_b(t_list **a, t_list **b, int p_size)
{
	int	median;
	int offset;
	int	p_asize;

	if (is_pt_sorted(&b, p_size))
		return (empty_partition_b(a, b, p_size));
	if (p_size <= 2)
		return (b_base_handler(a, b, p_size));
	median = find_medval(*b, p_size);
	offset = 0;
	while (p_asize < p_size)
	{
		if (vp_to_i((*a)->content) > median && p_size-- && p_asize++)
			action_dispatcher("pa", a, b);
		else if (++offset)
			action_dispatcher("rb", a, b);
	}
	reverse_offset(a, b, offset, 'b');
	sort_b(a, b, p_size);
	sort_a(a, b, p_asize);
}
