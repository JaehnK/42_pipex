# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 20:20:49 by jaehukim          #+#    #+#              #
#    Updated: 2024/06/07 17:01:52 by jaehukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEADR = pipex.h
CC = cc
CFLAGS = -I./libft -g

LIB = ./libft/libft.a
SUBDIR = ./libft

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = px_main.c
OBJS = $(SRCS:%.c=%.o)

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)
 
$(NAME): $(OBJS) $(LIB)

	@$(CC) $(CFLAGS) $(OBJS) -L$(SUBDIR) -lft -o $(NAME)

$(LIB):
	$(MAKE) -C $(SUBDIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADR)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -O3 -c $< -o $@

cclean:
	@$(MAKE) clean -C $(SUBDIR)
	rm -rf $(OBJS_DIR)/*.o

fclean: clean
	@$(MAKE) fclean -C $(SUBDIR)
	rm -rf $(NAME)
		
re: fclean all

.PHONY : all clean fclean re
