# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 19:04:24 by spoliart          #+#    #+#              #
#    Updated: 2021/12/27 17:24:22 by spoliart         ###   ########.fr        #
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

LEXER	=	tokenization.c \
			get_word_token.c \
			get_char_type.c \
			get_pipe_token.c \
			get_redirection_token.c \
			create_token.c \
			token_add_back.c \
			clear_tokens.c

PARSER	=	create_ast.c \
			parse_tokens.c \
			tokens_type.c \
			create_cmd.c \
			create_argv_cmd.c \
			check_redirection.c \
			parse_pipe.c \
			check_pipe.c \
			error_msg.c \
			create_pipe.c \
			ast_error.c \
			free_ast.c \
			skip_token.c \
			print_ast.c \
			get_ast.c

REDIRECTIONS	=	clear_redirections.c \
					open_redirections.c \
					heredoc_redirection.c \
					input_redirection.c \
					output_redirection.c \
					redirection_error.c \
					redirections.c \
					remove_redirections.c \
					heredoc_control.c \
					fill_doc.c

EXPANSIONS	=	expand_node.c \
				expanser.c \
				check_var_pos.c \
				incorrect_syntax_var.c \
				expand_vars.c \
				update_argv.c \
				expand_var.c \
				utils.c \
				realloc_argv.c \
				fill_new_argv.c \
				handle.c \
				init_expand.c \
				get_var.c \
				quotes.c \
				expand_stream_vars.c

UTILS	=	fd.c \
			lst.c \
			lstdelone.c \
			error.c \
			getenv.c \
			set_env.c \
			set_env2.c

SYSTEM	=	signals.c \
			init_env.c

BUILTIN	=	builtins.c \
			cd.c \
			pwd.c \
			env.c \
			exit.c \
			echo.c \
			unset.c \
			export.c

EXEC	=	exec.c \
			exec_cmd.c \
			exec_pipe.c \
			exec_utils.c \
			path.c

SRCS	=	main.c \
			$(LEXER) \
			$(PARSER) \
			$(REDIRECTIONS) \
			$(EXPANSIONS) \
			$(EXEC) \
			$(BUILTIN) \
			$(SYSTEM) \
			$(UTILS)

# [ OBJECTS ] #

OBJS	=	$(SRCS:%=$O%.o)

# [ PATH ] #

VPATH	=	includes:srcs:srcs/lexer:srcs/parser:srcs/redirection:srcs/expansion:srcs/exec:srcs/builtins:srcs/system:srcs/utils

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
