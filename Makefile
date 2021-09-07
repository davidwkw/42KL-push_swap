SRCS =	actions.c \
		a_base_handler.c \
		b_base_handler.c \
		median_handler.c \
		print_handler.c \
		push_swap.c \
		sort.c \
		utils.c \
		validator.c \
		check_sorted.c

OBJS = $(SRCS:.c=.o)

LIBFTDIR = libft

LIBFT = $(LIBFTDIR)/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@echo "Creating $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	@make -C $(LIBFTDIR) bonus

bonus : all

clean :
	@echo "Cleaning up $(OBJS)"
	@$(RM) $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean : clean
	@echo "Cleaning up $(NAME)"
	@$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus