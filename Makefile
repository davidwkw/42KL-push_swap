SRCDIR = srcs

SRCS =	$(SRCDIR)/actions.c \
		$(SRCDIR)/action_handler.c \
		$(SRCDIR)/a_base_handler.c \
		$(SRCDIR)/b_base_handler.c \
		$(SRCDIR)/median_handler.c \
		$(SRCDIR)/print_handler.c \
		$(SRCDIR)/push_swap.c \
		$(SRCDIR)/sort.c \
		$(SRCDIR)/utils.c \
		$(SRCDIR)/validator.c \
		$(SRCDIR)/check_sorted.c

OBJS = $(SRCS:.c=.o)

INCLUDES = includes

LIBFTDIR = libft

LIBFT = $(LIBFTDIR)/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -I$(INCLUDES)

NAME = push_swap

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@echo "Creating $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	@make -C $(LIBFTDIR) bonus

bonus : all

eval:
	@echo [500]
	@echo -n 'ARG="'
	@jot 1000 -1000 1000 | uniq | sort -R  |head -500 | tr '\n' ' '
	@echo '"; ./push_swap $$ARG'
	@echo [100]
	@echo -n 'ARG="'
	@jot 1000 -1000 1000 | uniq | sort -R  |head -100 | tr '\n' ' '
	@echo '"; ./push_swap $$ARG'
	@echo [Visualizer https://codepen.io/ahkoh/full/bGWxmVz]

test: bonus
	git clone https://github.com/lmalki-h/push_swap_tester.git || true
	cd push_swap_tester/ && bash tester.sh .. 3 20
	cd push_swap_tester/ && bash tester.sh .. 5 20
	cd push_swap_tester/ && bash tester.sh .. 100 100
	cd push_swap_tester/ && bash tester.sh .. 500 100

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