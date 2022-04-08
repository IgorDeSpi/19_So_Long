# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 11:09:30 by ide-spir          #+#    #+#              #
#    Updated: 2022/04/08 14:21:33 by ide-spir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = ./src/mandatory/gnl/get_next_line_utils.c \
	   ./src/mandatory/gnl/get_next_line.c \
	   ./src/mandatory/hooks.c \
	   ./src/mandatory/init.c \
	   ./src/mandatory/main.c \
	   ./src/mandatory/movements.c \
	   ./src/mandatory/draw_map.c \
	   ./src/mandatory/parsing_objects.c \
	   ./src/mandatory/parsing_struct.c \
	   ./src/mandatory/errors_6to10.c \
	   ./src/mandatory/errors_1to5.c \

OBJS = ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = ./src/libft/libft.a

.PHONY : all clean fclean re

all : $(NAME)
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(LIBFT) $(OBJS) -o $(NAME) $(LIBFT)

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(LIBFT) :
	@make -C ./src/libft

clean :
	@make -C ./src/libft fclean
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
