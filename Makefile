# Nom de l'exécutable
NAME = push_swap

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Dossiers
SRC_DIR = src
OBJ_DIR = obj
ALGO_DIR = $(SRC_DIR)/algorithm
OPERATIONS_DIR = $(SRC_DIR)/operations
PARSING_DIR = $(SRC_DIR)/parsing
STACK_DIR = $(SRC_DIR)/stack

OBJ_ALGO_DIR = $(OBJ_DIR)/algorithm
OBJ_OPERATIONS_DIR = $(OBJ_DIR)/operations
OBJ_PARSING_DIR = $(OBJ_DIR)/parsing
OBJ_STACK_DIR = $(OBJ_DIR)/stack

# Fichiers sources
SRC_FILES = push_swap.c 
ALGO_FILES = algorithm.c big_sort.c small_sort.c
OPERATIONS_FILES = sa.c sb.c ss.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c
PARSING_FILES = parsing.c
STACK_FILES = stack_init.c stack_utils.c

# Création des chemins vers les fichiers sources
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
       $(addprefix $(ALGO_DIR)/, $(ALGO_FILES)) \
       $(addprefix $(OPERATIONS_DIR)/, $(OPERATIONS_FILES)) \
       $(addprefix $(PARSING_DIR)/, $(PARSING_FILES)) \
       $(addprefix $(STACK_DIR)/, $(STACK_FILES))

# Création des chemins vers les fichiers objets
OBJS = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRCS:.c=.o))

# Commandes de compilation
all: $(OBJ_DIR) $(OBJ_ALGO_DIR) $(OBJ_OPERATIONS_DIR) $(OBJ_PARSING_DIR) $(OBJ_STACK_DIR) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/algorithm/%.o: $(ALGO_DIR)/%.c | $(OBJ_ALGO_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/operations/%.o: $(OPERATIONS_DIR)/%.c | $(OBJ_OPERATIONS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/parsing/%.o: $(PARSING_DIR)/%.c | $(OBJ_PARSING_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/stack/%.o: $(STACK_DIR)/%.c | $(OBJ_STACK_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création des dossiers si besoin
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_ALGO_DIR): | $(OBJ_DIR)
	@mkdir -p $(OBJ_ALGO_DIR)

$(OBJ_OPERATIONS_DIR): | $(OBJ_DIR)
	@mkdir -p $(OBJ_OPERATIONS_DIR)

$(OBJ_PARSING_DIR): | $(OBJ_DIR)
	@mkdir -p $(OBJ_PARSING_DIR)

$(OBJ_STACK_DIR): | $(OBJ_DIR)
	@mkdir -p $(OBJ_STACK_DIR)

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

# Nettoyage complet (objets + exécutable)
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Recompilation
re: fclean all

bonus: all

.PHONY: all clean fclean re bonus