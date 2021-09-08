#include "push_swap.h"

static void	a_base_2_handler(t_list **a)
{
	int	first;
	int	second;

	first = vp_to_i((*a)->content);
	second = vp_to_i((*a)->next->content);
	if (first > second)
		action_dispatcher("sa", a, NULL);
}

static void	a_base_3_handler(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = vp_to_i((*a)->content);
	second = vp_to_i((*a)->next->content);
	third = vp_to_i((*a)->next->next->content);
	if (first > second && second < third && first < third)
		action_dispatcher("sa", a, NULL);
	else if (first > second && second < third && first > third)
		action_dispatcher("ra", a, NULL);
	else if (first < second && second > third && first > third)
		action_dispatcher("rra", a, NULL);
	else if (first < second && second > third && first < third)
		action_dispatcher("sa ra", a, NULL);
	else if (first > second && second > third && first > third)
		action_dispatcher("sa rra", a, NULL);
}

static void	a_partition_base_3_handler(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = vp_to_i((*a)->content);
	second = vp_to_i((*a)->next->content);
	third = vp_to_i((*a)->next->next->content);
	if (first > second && second < third && first < third)
		action_dispatcher("sa", a, NULL);
	else if (first > second && second < third && first > third)
		action_dispatcher("sa ra sa rra", a, NULL);
	else if (first < second && second > third && first > third)
		action_dispatcher("ra sa rra sa", a, NULL);
	else if (first < second && second > third && first < third)
		action_dispatcher("ra sa rra", a, NULL);
	else if (first > second && second > third && first > third)
		action_dispatcher("sa ra sa rra sa", a, NULL);
}

void	a_base_handler(t_list **a, int size)
{
	int total_stack_size;

	total_stack_size = ft_lstsize(*a);
	if (size == 2)
		a_base_2_handler(a);
	else if (size == 3 && size == total_stack_size)
		a_base_3_handler(a);
	else if (size == 3 && size != total_stack_size)
		a_partition_base_3_handler(a);
}