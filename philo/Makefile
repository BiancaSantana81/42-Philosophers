# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 13:31:36 by bsantana          #+#    #+#              #
#    Updated: 2024/07/05 11:54:48 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN := \033[1;32m
WHITE := \033[1;37m
BOLD := \033[1;33m

NAME := philo
CFLAGS := -Wextra -Wall -Werror -g3
MAKEFLAGS += --silent
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes
HELGRIND_FLAGS := --tool=helgrind

# PATHS
CC := cc
OBJ_PATH := objects

# SOURCES
CFILES := trash.c main.c utils.c check_input.c init.c
OBJS := $(addprefix $(OBJ_PATH)/, $(notdir $(CFILES:.c=.o)))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)------------------------------------------------  "
	@echo "$(WHITE) 🍽️  Are you ready for our philosophical dinner? 🍽️"
	@echo "$(GREEN)------------------------------------------------  "

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "                                         "
	@echo "$(WHITE)        🧽 Washing the dishes 🧽 "
	@rm -rf $(NAME)
	@echo "$(WHITE)              -----------        "
	@echo "$(WHITE)           Cleaning complete!    "
	@echo "                                     "

re: fclean all

val: ARGS=""
val:
	@$(MAKE) re
	@valgrind $(VALGRIND_FLAGS) ./$(NAME) $(ARGS)

hel: ARGS=""
hel:
	@$(MAKE) re
	@valgrind $(HELGRIND_FLAGS) ./$(NAME) $(ARGS)

.PHONY: all clean fclean re
