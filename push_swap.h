#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "./libft/libft.h"

void	error_handler(char *error);
int		*validate_int_args(int *arrc, char *arr[]);
int		vp_to_i(void *ptr);
void	free_arr(void **ptr, int i, int n);

int		swap(t_list **el);
int		push(t_list **stack1, t_list **stack2);
int		rotate(t_list **head);
int		reverse_rotate(t_list **head);
void	action_dispatcher(char *action, t_list **a, t_list **b);

void	sort_list(t_list **a, t_list **b, int size);

void	a_base_2_handler(t_list **stack);
void	a_base_3_handler(t_list **stack);
void	a_base_handler(t_list **a, int size);
void	b_base_handler(t_list **a, t_list **b, int size);
int		find_medval(t_list *stack, int size);

void	print_handler(char *str);

#endif