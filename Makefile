# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 13:31:36 by bsantana          #+#    #+#              #
#    Updated: 2024/07/01 14:29:49 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN :=	\033[1;32m
WHITE :=	\033[1;37m
BOLD :=	\033[1;33m

NAME		:= philo
CFLAGS		:= -Wextra -Wall -Werror -g3
MAKEFLAGS += --silent

# PATHS
CC			:= cc
SRC_PATH 	:= sources
OBJ_PATH	:= objects

# SOURCES
CFILES      := main.c \

#PATH_FILES
SRCS		:= $(addprefix $(SRC_PATH)/, $(CFILES))
OBJS		:= $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))

#HEADERS
HEADERS		:= -I ./includes
HEADER_FILE := includes/philo.h

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_FILE) | $(OBJ_PATH)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)------------------------------  "
	@echo "$(WHITE) 🍽️  The dinner was served 🍽️"
	@echo "$(GREEN)------------------------------  "

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

.PHONY: all, clean, fclean, re