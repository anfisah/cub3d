# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 15:29:29 by ccoto             #+#    #+#              #
#    Updated: 2021/03/03 11:04:55 by ccoto            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

SRCS =		ft_isalpha.c ft_memcmp.c ft_putendl_fd.c ft_strjoin.c \
			ft_strncmp.c ft_toupper.c ft_atoi.c ft_isascii.c  \
			ft_memcpy.c ft_putnbr_fd.c ft_strlcat.c ft_strnstr.c ft_bzero.c \
			ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_strlcpy.c \
			ft_strrchr.c ft_calloc.c ft_isprint.c ft_memccpy.c ft_memset.c \
			ft_strchr.c ft_strlen.c ft_substr.c ft_isalnum.c ft_itoa.c ft_memchr.c \
			ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_strtrim.c \
			ft_split.c ft_strdel.c ft_2dstrdel.c

SRCSBONUS =	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstadd_front.c \
			ft_lstsize.c

OBJS = 		${SRCS:.c=.o}

OBJSBONUS = ${SRCSBONUS:.c=.o}

CC = 		gcc

FLAGS = 	-Wall -Wextra -Werror 

RM = 		rm -f

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I .

${NAME}: 	${OBJS}
		 	ar -rcs ${NAME} ${OBJS}

bonus:  	${NAME} ${OBJSBONUS}
			ar -rcs ${NAME} ${OBJSBONUS}

all: 		${NAME}

clean: 
			${RM} ${OBJS} ${OBJSBONUS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

.PHONY: 	all clean fclean re
