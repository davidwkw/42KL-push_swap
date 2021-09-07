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
	t_list	*last;

	if (!head)
		return (0);
	last = *head;
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
	temp = *head;
	while (temp->next->next)
		temp = temp->next;
	last = ft_lstlast(*head);
	ft_lstadd_front(head, last);
	temp->next = NULL;
	return (1);
}
