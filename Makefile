# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 20:20:49 by jaehukim          #+#    #+#              #
#    Updated: 2024/06/19 12:29:57 by jaehukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipex_bonus
HEADR = ./includes/pipex.h
HEADR_BONUS = ./includes/pipex_bonus.h
CC = cc
CFLAGS = -I./libft -Wall -Werror -Wextra -fsanitize=address -g -static-libsan

LIB = ./libft/libft.a
SUBDIR = ./libft

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =	px_main.c \
		px_parse.c \
		px_pipe.c \
		px_exe.c

SRCS_BONUS = px_bonus_main.c \
			 px_bonus_parse.c \
			 px_bonus_pipe.c \
			 px_bonus_exe.c


SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

SRCS_BONUS := $(addprefix $(SRCS_DIR)/, $(SRCS_BONUS))
OBJS_BONUS := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS_BONUS:.c=.o)))

all: $(NAME)
 
$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) -L$(SUBDIR) -lft -o $(NAME)

$(LIB):
	@$(MAKE) -C $(SUBDIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADR)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME) $(NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(SUBDIR) -lft -o $(BONUS_NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADR_BONUS)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(SUBDIR)
	@rm -rf $(OBJS_DIR)/*.o

fclean: clean
	@$(MAKE) fclean -C $(SUBDIR)
	@rm -rf $(NAME) $(BONUS_NAME)
		
re: fclean all

.PHONY : all clean fclean re
