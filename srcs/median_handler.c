#include "push_swap.h"
#include <limits.h>

static int	find_min(t_list *stack, int size)
{
	int	min;
	int	i;

	i = -1;
	min = vp_to_i(stack->content);
	while (++i < size)
	{
		if (vp_to_i(stack->content) < min)
			min = vp_to_i(stack->content);
		stack = stack->next;
	}
	return (min);
}

static void insertion_sort(t_list *stack, int *arr, int size)
{
	int		curr_value;
	t_list	*temp;
	int		i;
	int		j;
	
	i = 0;
	arr[i++] = find_min(stack, size);
	while (i < size)
	{
		arr[i] = INT_MAX;
		temp = stack;
		j = -1;
		while (++j < size)
		{
			curr_value = vp_to_i(temp->content);
			if (curr_value > arr[i - 1] && curr_value < arr[i])
				arr[i] = curr_value;
			temp = temp->next;
		}
		i++;
	}
}

int	find_medval(t_list *stack, int size)
{
	int	*sorted_arr;
	int	median;

	sorted_arr = malloc(sizeof(int) * size);
	if (!sorted_arr)
		return (0);
	insertion_sort(stack, sorted_arr, size);
	median = sorted_arr[size / 2];
	free(sorted_arr);
	return (median);
}
