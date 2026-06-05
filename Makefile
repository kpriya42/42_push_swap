# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/24 13:31:36 by kri-              #+#    #+#              #
#    Updated: 2026/06/05 18:34:07 by kri-             ###   ########.fr        #
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
SRCS = test_file_1.c \
		main.c \
		algo_complex.c \
		algo_medium.c \
		algo_simple.c \
    	check_args.c \
    	clean_args.c \
		init_stack.c \
		push_swap_utils_1.c \
		push_swap_utils_2.c \
		push_swap.c \
		operation_swap.c \
		operation_rotate.c \
		operation_revrotate.c \
		operation_push.c \
		bench_output.c
	   
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

# delete *.o files
clean:
	$(RM) -r $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

# remove *.o and *.a  files
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# rebuild
re: fclean all

.PHONY: all clean fclean re