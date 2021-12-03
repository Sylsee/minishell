# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 19:04:24 by spoliart          #+#    #+#              #
#    Updated: 2021/12/03 02:36:53 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# [ VARIABLES ] #
SHELL	=	/bin/sh
NAME	=	minishell
RM		=	/bin/rm -rf
MAKE	=	make
LIBFT	=	libft

# [ COLORS ] #

_END	=	\e[0m
_RED	=	\e[31m
_GREEN	=	\e[32m
_YELLOW	=	\e[33m

# [ COMPILATION VARIABLES ]#

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
LDFLAGS	=	-lreadline -Llibft -lft

# [ VALGRIND VARIABLES ] #

VALGRIND	=	/usr/bin/valgrind
VFLAGS		=	--suppressions=ignoreliberror --leak-check=full --show-leak-kinds=all --track-origins=yes

# [ DIRECTORIES ] #

S		=	srcs/
O		=	objs/
I		=	-I./includes

# [ SOURCES ] #

SYSTEM	=	signals.c \
			init_env.c

BUILTIN	=	builtins.c \
			env.c \
			echo.c

EXEC	=	exec.c \
			exec_cmd.c \
			exec_pipe.c \
			exec_utils.c \
			path.c

SRCS	=	main.c \
			error.c \
			utils.c \
			$(EXEC) \
			$(BUILTIN) \
			$(SYSTEM)

# [ OBJECTS ] #

OBJS	=	$(SRCS:%=$O%.o)

# [ PATH ] #

VPATH	=	includes:srcs:srcs/lexer:srcs/exec:srcs/builtins:srcs/system

# [ RULES ] #

all:		$(NAME)

$(NAME):	$(OBJS)
			@printf "\033[2K\r$(_GREEN) All files compiled into '$O'. $(_END)✅\n"
			@$(MAKE) -s -C $(LIBFT)
			@$(CC) $(CFLAGS) $^ -o $@ $I $(LDFLAGS)
			@printf "$(_GREEN) Binary '$(NAME)' created. $(_END)✅\n"

$O:
			@mkdir -p $@

$O%.o:		%	| $O
			@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛"
			@$(CC) $(CFLAGS) $I -c $< -o $@

clean:
			@make -s clean -C $(LIBFT)
			@$(RM) $O
			@printf "$(_RED) '$O' has been deleted. $(_END)🗑️\n"

fclean:		clean
			@make -s fclean -C $(LIBFT)
			@$(RM) $(NAME)
			@printf "$(_RED) '$(NAME)' has been deleted. $(_END)🗑️\n"

re:			fclean all

valgrind: 	all
			@$(VALGRIND) $(VFLAGS) ./$(NAME)

# [ PHONY ] #

.PHONY:	all clean fclean re
