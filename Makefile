# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 11:09:30 by ide-spir          #+#    #+#              #
#    Updated: 2022/04/19 15:26:46 by ide-spir         ###   ########.fr        #
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

SRCS_B = ./src/bonus/draw_map_bonus.c \
		./src/bonus/errors_1to5_bonus.c \
		./src/bonus/errors_6to10_bonus.c \
		./src/bonus/hooks_bonus.c \
		./src/bonus/init_bonus.c \
		./src/bonus/loops_bonus.c \
		./src/bonus/main_bonus.c \
		./src/bonus/movements_bonus.c \
		./src/bonus/parsing_objects_bonus.c \
		./src/bonus/parsing_struct_bonus.c \
		./src/bonus/gnl/get_next_line_bonus.c \
		./src/bonus/gnl/get_next_line_utils_bonus.c


OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

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
	@rm -f $(OBJS) $(OBJS_B)

fclean : clean
	@rm -f $(NAME)

re : fclean all

bonus: $(LIBFT) $(OBJS_B)
	$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(LIBFT) $(OBJS_B) -o $(NAME) $(LIBFT)
