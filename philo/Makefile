# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 13:31:36 by bsantana          #+#    #+#              #
#    Updated: 2024/07/15 11:01:13 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN := \033[1;32m
WHITE := \033[1;37m
BOLD := \033[1;33m

NAME := philo
CFLAGS :=  -Wextra -Wall -Werror
MAKEFLAGS += --silent
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes
HELGRIND_FLAGS := --tool=helgrind

# PATHS
CC := cc
OBJ_PATH := objects

# SOURCES
CFILES := 0_philosophers.c 1_input.c 2_data.c 3_dinner.c 4_1_control.c \
		4_2_routine.c 4_3_time.c 5_actions.c 6_clean.c utils.c
OBJS := $(addprefix $(OBJ_PATH)/, $(notdir $(CFILES:.c=.o)))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -pthread -o $(NAME)
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
