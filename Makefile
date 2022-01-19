# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmustin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 15:02:35 by fmustin           #+#    #+#              #
#    Updated: 2022/01/05 15:02:37 by fmustin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	srcs/main.c \
					srcs/data.c \
					srcs/operations.c \
					srcs/stack.c \
					srcs/stack_utils.c \
					srcs/sort_small_stack.c \
					srcs/sort_big_stack.c \
					srcs/utils.c \

INCLUDES		= includes/main.h

OBJS	= ${SRCS:.c=.o}

NAME 	= push_swap

CC			= gcc
CCFLAGS 	= -Wall -Wextra -Werror -fsanitize=address

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I ${INCLUDES} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS} ${INCLUDES}
			$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

clean:
				rm -f ${OBJS}

fclean: 	clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
