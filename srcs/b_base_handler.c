#include "push_swap.h"

void	b_base_2_handler(t_list **b)
{
	int	first;
	int	second;

	first = vp_to_i((*b)->content);
	second = vp_to_i((*b)->next->content);
	if (first < second)
		action_dispatcher("sb", NULL, b);
}

static void	b_base_3_handler(t_list **b)
{
	int	first;
	int	second;
	int	third;

	first = vp_to_i((*b)->content);
	second = vp_to_i((*b)->next->content);
	third = vp_to_i((*b)->next->next->content);
	if (first > second && second < third && first < third)
		action_dispatcher("rrb", NULL, b);
	else if (first > second && second < third && first > third)
		action_dispatcher("rrb sb", NULL, b);
	else if (first < second && second > third && first > third)
		action_dispatcher("sb", NULL, b);
	else if (first < second && second > third && first < third)
		action_dispatcher("rb", NULL, b);
	else if (first < second && second < third && first < third)
		action_dispatcher("sb rrb", NULL, b);
}

static void	b_partition_base_3_handler(t_list **b)
{
	int	first;
	int	second;
	int	third;

	first = vp_to_i((*b)->content);
	second = vp_to_i((*b)->next->content);
	third = vp_to_i((*b)->next->next->content);
	if (first > second && second < third && first < third)
		action_dispatcher("rb sb rrb sb", NULL, b);
	else if (first > second && second < third && first > third)
		action_dispatcher("rb sb rrb", NULL, b);
	else if (first < second && second > third && first > third)
		action_dispatcher("sb", NULL, b);
	else if (first < second && second > third && first < third)
		action_dispatcher("sb rb sb rrb", NULL, b);
	else if (first < second && second < third && first < third)
		action_dispatcher("sb rb sb rrb sb", NULL, b);
}

void	b_base_handler(t_list **a, t_list **b, int size)
{
	int total_stack_size;

	total_stack_size = ft_lstsize(*b);
	if (size == 2)
		b_base_2_handler(b);
	else if (size == 3 && size == total_stack_size)
		b_base_3_handler(b);
	else if (size == 3 && size != total_stack_size)
		b_partition_base_3_handler(b);
	empty_partition_b(a, b, size);
}