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
	if (first > second && first < third && second < third)
		action_dispatcher("sa", a, NULL);
	else if (first > second && second < third && first > third)
		action_dispatcher("ra", a, NULL);
	else if (first < second && second > third && first > third)
		action_dispatcher("rra", a, NULL);
	else if (first < second && second > third && first < third)
	{
		action_dispatcher("sa", a, NULL);
		action_dispatcher("ra", a, NULL);
	}
	else if (first > second && second > third && first > third)
	{
		action_dispatcher("sa", a, NULL);
		action_dispatcher("rra", a, NULL);
	}
}

void	b_base_handler(t_list **a, t_list **b, int size)
{
	int	first;
	int	second;
	int	i;

	first = vp_to_i((*b)->content);
	second = vp_to_i((*b)->next->content);
	if (second > first)
		action_dispatcher("sb", NULL, b);
	i = -1;
	while (++i < size)
		action_dispatcher("pa", a, b);
}

void	a_base_handler(t_list **a, int size)
{
	if (size == 2)
		a_base_2_handler(a);
	else if (size == 3)
		a_base_3_handler(a);
}