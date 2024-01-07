#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/libft.h"

void	init_structs(t_list **a_head, t_list **b_head);
void	fill_stack(t_list **stack_a, int argc, long *list);

void	error_handler(char *error);
long	*validate_int_args(int *arrc, char **arr);
int		vp_to_i(void *ptr);
int		arr_len(char **arr);
void	free_nested_arr(char **arr);
void	clear_list(t_list **lst);

int		swap(t_list **el);
int		push(t_list **stack1, t_list **stack2);
int		rotate(t_list **head);
int		reverse_rotate(t_list **head);
int		combo_swap(t_list **a, t_list **b);
int		combo_rotate(t_list **a, t_list **b);
int		combo_reverse_rotate(t_list **a, t_list **b);
int		action_handler(char *action, t_list **a, t_list **b);
void	action_dispatcher(char *action, t_list **a, t_list **b);

void	sort_a(t_list **a, t_list **b, int size);
void	sort_b(t_list **a, t_list **b, int p_size);

int		is_a_sorted(t_list *head, int size);
int		is_b_sorted(t_list *head, int size);
void	empty_partition_b(t_list **a, t_list **b, int size);

void	a_base_handler(t_list **a, int size);
void	b_base_handler(t_list **a, t_list **b, int size);
int		find_medval(t_list *stack, int size);

void	print_handler(char *str);

#endif
