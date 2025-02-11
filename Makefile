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
OPERATIONS_DIR = $(SRC_DIR)/operations
OBJ_OPERATIONS_DIR = $(OBJ_DIR)/operations

# Fichiers sources
SRC_FILES = push_swap.c check_arguments.c stack.c
OPERATIONS_FILES = sa.c

# Création des chemins vers les fichiers sources et objets
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OPERATIONS_SRCS = $(addprefix $(OPERATIONS_DIR)/, $(OPERATIONS_FILES))
OBJS = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRCS:.c=.o)) \
       $(patsubst $(OPERATIONS_DIR)/%, $(OBJ_OPERATIONS_DIR)/%, $(OPERATIONS_SRCS:.c=.o))

# Commandes de compilation
all: $(OBJ_DIR) $(OBJ_OPERATIONS_DIR) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_OPERATIONS_DIR)/%.o: $(OPERATIONS_DIR)/%.c | $(OBJ_OPERATIONS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création des dossiers si besoin
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_OPERATIONS_DIR): | $(OBJ_DIR)
	@mkdir -p $(OBJ_OPERATIONS_DIR)

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