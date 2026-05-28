# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/24 13:31:36 by kri-              #+#    #+#              #
#    Updated: 2026/05/28 13:59:20 by kri-             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS_DIR = src
SRCS = main.c \
       check_args.c \
       clean_args.c
	   
OBJS_DIR = obj
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build executable
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Compile objects
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	$(RM) -r $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re