# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 19:04:24 by spoliart          #+#    #+#              #
#    Updated: 2021/10/16 06:11:50 by spoliart         ###   ########.fr        #
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
I=includes/

## FILES ##

SRCS=	main.c \
		echo.c

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
		@$(CC) $(CFLAGS) $^ -o $@ -I $I $(LDFLAGS)
		@printf "$(_GREEN) Binary '$(NAME)' created. $(_END)✅\n"

$O%.o:	$S%.c
		@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛"
		@$(CC) $(CFLAGS) -I $I -c $< -o $@

$(OBJS):	| $O

$O:
		mkdir -p $O

clean:
		@make -s clean -C libft
		@$(RM) $(DIR_OBJS)
		@printf "$(_RED) '$O' has been deleted. $(_END)🗑️\n"

fclean:	clean
		@make -s fclean -C libft
		@$(RM) $(NAME)
		@printf "$(_RED) '$(NAME)' has been deleted. $(_END)🗑️\n"

re:	fclean all

## PHONY ##

.PHONY:	all clean fclean re
