# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 11:01:28 by ccoto             #+#    #+#              #
#    Updated: 2021/03/09 09:59:58 by ccoto            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = parsing/parse_map.c parsing/get_next_line.c srcs/infos_struct.c \
parsing/infos_map.c parsing/flood_fill.c parsing/check_errors.c \
parsing/utils.c srcs/cub3d.c srcs/raycasting.c srcs/move.c srcs/keypress.c \
bmp.c srcs/sprite.c srcs/turn.c parsing/utils2.c srcs/raycasting2.c \
srcs/sprite2.c srcs/info_struct2.c

OBJS = ${SRCS:.c=.o}

CC  = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I .

all:	subsystem ${NAME}

${NAME}: ${OBJS} libft/libft.a mlx/libmlx.dylib
		${CC} ${FLAGS} libmlx.dylib libft/libft.a ${OBJS} -o ${NAME}

subsystem:
		make -C mlx/ 
		make -C Libft/
		cp mlx/libmlx.dylib .

subclean:
		make clean -C mlx/
		make clean -C Libft/

clean:	subclean
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} libmlx.dylib libft.a

re:		fclean all

.PHONY:	all clean fclean re