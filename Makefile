SRCDIR = srcs

SRCS =	$(SRCDIR)/actions.c \
		$(SRCDIR)/action_handler.c \
		$(SRCDIR)/a_base_handler.c \
		$(SRCDIR)/b_base_handler.c \
		$(SRCDIR)/median_handler.c \
		$(SRCDIR)/print_handler.c \
		$(SRCDIR)/sort.c \
		$(SRCDIR)/utils.c \
		$(SRCDIR)/validator.c \
		$(SRCDIR)/check_sorted.c \
		$(SRCDIR)/init_stack.c \
		$(SRCDIR)/combo_actions.c

OBJS = $(SRCS:.c=.o)

PS_SRCS = $(SRCDIR)/push_swap/push_swap.c \

PS_OBJS = $(PS_SRCS:.c=.o)

GNL_DIR = get_next_line

GNL_SRCS =	$(GNL_DIR)/get_next_line.c \
			$(GNL_DIR)/get_next_line_utils.c

GNL_OBJS = $(GNL_SRCS:.c=.o)

BONUS_SRCS = $(SRCDIR)/checker/checker.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

INCLUDES = includes

LIBFTDIR = libft

LIBFT = $(LIBFTDIR)/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=4 -I$(INCLUDES)

NAME = push_swap

BONUS = checker

all : $(NAME) $(BONUS)

bonus : $(BONUS)

$(LIBFT) :
	@make -C $(LIBFTDIR) bonus

$(NAME) : $(LIBFT) $(OBJS) $(PS_OBJS)
	@echo "Creating $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(PS_OBJS) $(LIBFT) -o $@

$(BONUS) : $(LIBFT) $(OBJS) $(GNL_OBJS) $(BONUS_OBJS)
	@echo "Creating $(BONUS)"
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(BONUS_OBJS) $(LIBFT) -o $@

eval : 
	@echo [500]
	@echo -n 'ARG="'
	@jot 1000 -1000 1000 | uniq | sort -R  |head -500 | tr '\n' ' '
	@echo '"; ./push_swap $$ARG'
	@echo [100]
	@echo -n 'ARG="'
	@jot 1000 -1000 1000 | uniq | sort -R  |head -100 | tr '\n' ' '
	@echo '"; ./push_swap $$ARG'
	@echo [Visualizer https://codepen.io/ahkoh/full/bGWxmVz]

test : bonus
	git clone https://github.com/lmalki-h/push_swap_tester.git || true
	cd push_swap_tester/ && bash tester.sh .. 3 20
	cd push_swap_tester/ && bash tester.sh .. 5 20
	cd push_swap_tester/ && bash tester.sh .. 100 100
	cd push_swap_tester/ && bash tester.sh .. 500 100

clean :
	@echo "Cleaning up $(OBJS) $(BONUS_OBJS) $(PS_OBJS) $(GNL_OBJS)"
	@$(RM) $(OBJS) $(BONUS_OBJS) $(PS_OBJS) $(GNL_OBJS)
	@make -C $(LIBFTDIR) clean

fclean : clean
	@echo "Cleaning up $(NAME) $(BONUS)"
	@$(RM) $(NAME) $(BONUS)
	@make -C $(LIBFTDIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus test eval