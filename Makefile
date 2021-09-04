SRCS =	actions.c \
		base_case_handler.c \
		median_handler.c \
		print_handler.c \
		push_swap.c \
		sort.c \
		utils.c \
		validator.c 

OBJS = $(SRCS:.c=.o)

LIBFTDIR = libft

LIBFT = $(LIBFTDIR)/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I.

NAME = push_swap

$(LIBFT):
	@make -C $(LIBFTDIR) all

all : $(NAME)

$(NAME) : $(LIBFT)
	@echo "Creating $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

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