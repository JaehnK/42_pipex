# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 20:20:49 by jaehukim          #+#    #+#              #
#    Updated: 2024/06/04 20:53:03 by jaehukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEADR = pipex.h
CC = cc
CFLAGS = -g -fsanitize=address -I./libft

LIB = ./libft/libft.a
SUBDIR = ./libft

SRCS = px_main.c
OBJS = $(SRCS:%.c=%.o)

all : $(NAME)
 
%.o: %.c $(HEADR)
	@$(CC) $(CFLAGS) -O3 -c $< -o $@

$(NAME) : $(OBJS)
		@make -C ./libft
		@$(CC) $(CFLAGS) $(OBJS) -L$(SUBDIR) $(LIB) -lft -o $(NAME)

clean:
	@make clean -C $(SUBDIR)
	rm -rf $(OBJS)

fclean: clean
	@make fclean -C $(SUBDIR)
	rm -rf $(NAME)
		
re: fclean all

.PHONY : all clean fclean re
