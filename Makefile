# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:09:18 by mdelforg          #+#    #+#              #
#    Updated: 2022/04/06 16:40:41 by mdelforg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = srcs/main.c \
	   srcs/builtins.c \
	   srcs/libft.c \
	   srcs/libft_str.c \
	   srcs/environnement.c \
	   srcs/built_export.c \
	   srcs/built_cd.c \
	   srcs/built_unset.c

OBJS = $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

exe:		all clean

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		exe clean fclean re
