# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 15:47:20 by mcarton           #+#    #+#              #
#    Updated: 2025/02/11 15:54:15 by mcarton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

# Fichiers sources
SRC_FILES = push_swap.c check_arguments.c stack.c

# Création des chemins vers les fichiers sources et objets
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Commandes de compilation
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

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