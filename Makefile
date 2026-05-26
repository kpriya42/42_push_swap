# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/24 13:31:36 by kri-              #+#    #+#              #
#    Updated: 2026/05/26 17:25:30 by kri-             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I . include/push_swap.h 
OBJS_DIR = obj

SRCS = main.c push_swap.c \
		check_args.c  clean_args.c \
		operatio_push.c operation_swap.c operation_rotate.c operation_revrotate.c
		

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c include/push_swap.h | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
all:	${NAME}

clean:
		$(RM) -r $(OBJS_DIR)

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re