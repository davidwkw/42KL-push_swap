#include "push_swap.h"

int	swap(t_list **el)
{
	t_list	*temp;

	if (*el == NULL || (*el)->next == NULL)
		return (0);
	temp = (*el)->next->next;
	ft_lstadd_front(el, (*el)->next);
	(*el)->next->next = temp;
	return (1);
}

int	push(t_list **el, t_list **stack)
{
	t_list	*temp;

	if (*el == NULL)
		return (0);
	temp = (*el)->next;
	ft_lstadd_front(stack, *el);
	*el = temp;
	return (1);
}

int	rotate(t_list **head)
{
	t_list	*temp;
	t_list	*last;

	if (!head)
		return (0);
	last = *head;
	while (last->next->next)
		last = last->next;
	ft_lstadd_back(head, *head);
	*head = (*head)->next;
	last->next = NULL;
	return (1);
}

int	reverse_rotate(t_list **head)
{
	t_list	*temp;
	t_list	*last;

	if (!head)
		return (0);
	last = *head;
	while (last->next->next)
		last = last->next;
	temp = ft_lstlast(*head);
	ft_lstadd_front(head, temp);
	last->next = NULL;
	return (1);
}

void	action_dispatcher(char *action, t_list **a, t_list **b)
{
	int success;

	success = 0;
	if (!ft_strncmp(action, "sa", 2))
		success = swap(a);
	else if (!ft_strncmp(action, "sb", 2))
		success = swap(b);
	else if (!ft_strncmp(action, "pa", 2))
		success = push(b, a);
	else if (!ft_strncmp(action, "pb", 2))
		success = push(a, b);
	else if (!ft_strncmp(action, "ra", 2))
		success = rotate(a);
	else if (!ft_strncmp(action, "rb", 2))
		success = rotate(b);
	else if (!ft_strncmp(action, "rra", 3))
		success = reverse_rotate(a);
	else if (!ft_strncmp(action, "rrb", 3))
		success = reverse_rotate(b);
	if (success)
		print_handler(action);
}