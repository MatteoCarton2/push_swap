NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Files
SRCS = src/push_swap.c \
       src/algorithm/algorithm.c \
       src/algorithm/small_sort.c \
       src/algorithm/big_sort_a.c \
       src/algorithm/big_sort_b.c \
       src/operations/sa.c \
       src/operations/sb.c \
       src/operations/ss.c \
       src/operations/pa.c \
       src/operations/pb.c \
       src/operations/ra.c \
       src/operations/rb.c \
       src/operations/rr.c \
       src/operations/rra.c \
       src/operations/rrb.c \
       src/operations/rrr.c \
       src/parsing/parsing.c \
       src/stack/stack_init.c \
       src/stack/stack_utils.c

OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re