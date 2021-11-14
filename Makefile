# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 19:04:24 by spoliart          #+#    #+#              #
#    Updated: 2021/11/14 11:23:40 by arguilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###### VARIABLES ######


## CUSTOMIZATION ##

_END=\e[0m

_RED=\e[31m
_GREEN=\e[32m
_YELLOW=\e[33m

## COMPILATION ##

CC=gcc
CFLAGS+=-Wall -Wextra -Werror -g
LDFLAGS+=-lreadline -Llibft -lft

## DELETE ##

RM=rm -rf

## DIRECTORIES ##

S=srcs/
O=objs/
I=-I./includes/ -I./$Slexer/

## FILES ##

SRCS=	main.c \
		echo.c \
		env.c \
		error.c\
		lexer/tokenization.c\
		lexer/get_word_token.c\
		lexer/get_char_type.c\
		lexer/get_pipe_token.c\
		lexer/get_redirection_token.c\
		lexer/create_token.c\
		lexer/token_add_back.c\
		lexer/clear_tokens.c\
		utils/ft_isspace.c\
		utils/ft_strndup.c\

## COMPILED ##

OBJS=$(SRCS:%.c=$O%.o)

NAME=minishell

# **************************************************************************** #

###### RULES ######

all:	$(NAME)

## VARIABLES RULES ##

$(NAME):	$(OBJS)
		@printf "\033[2K\r$(_GREEN) All files compiled into '$O'. $(_END)✅\n"
		@make -s -C libft
		@$(CC) $(CFLAGS) $^ -o $@ $I $(LDFLAGS)
		@printf "$(_GREEN) Binary '$(NAME)' created. $(_END)✅\n"

$O%.o:	$S%.c
		@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛"
		@$(CC) $(CFLAGS) $I -c $< -o $@

$(OBJS):	| $O

$O:
		@mkdir -p $O
		@mkdir -p $O/lexer
		@mkdir -p $O/utils

clean:
		@make -s clean -C libft
		@$(RM) $O
		@printf "$(_RED) '$O' has been deleted. $(_END)🗑️\n"

fclean:	clean
		@make -s fclean -C libft
		@$(RM) $(NAME)
		@printf "$(_RED) '$(NAME)' has been deleted. $(_END)🗑️\n"

re:	fclean all

valgrind: all
		@valgrind --suppressions=ignoreliberror --leak-check=full --show-leak-kinds=all --track-origins=yes  ./minishell

## PHONY ##

.PHONY:	all clean fclean re
