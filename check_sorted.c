#include "push_swap.h"

int	is_pt_sorted(t_list *head, int size)
{
	int i;

	i = 0;
	while (i < size && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
		i++;
	}
	return (1);
}