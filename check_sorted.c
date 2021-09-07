#include "push_swap.h"

int	is_a_sorted(t_list *head, int size)
{
	int i;

	i = 0;
	while (i < size && head->next)
	{
		if (vp_to_i(head->content) > vp_to_i(head->next->content))
			return (0);
		head = head->next;
		i++;
	}
	return (1);
}

int	is_b_sorted(t_list *head, int size)
{
	int i;

	i = 0;
	while (i < size && head->next)
	{
		if (vp_to_i(head->content) < vp_to_i(head->next->content))
			return (0);
		head = head->next;
		i++;
	}
	return (1);
}