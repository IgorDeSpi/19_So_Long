# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:32:13 by ide-spir          #+#    #+#              #
#    Updated: 2022/04/06 17:22:30 by ide-spir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #

NAME = libft.a

# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_split.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strmapi.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_tolower.c \
	   ft_toupper.c

SRCS_BONUS = ft_lstadd_back.c \
			 ft_lstadd_front.c \
			 ft_lstclear.c \
			 ft_lstdelone.c \
			 ft_lstiter.c \
			 ft_lstlast.c \
			 ft_lstmap.c \
			 ft_lstnew.c \
			 ft_lstsize.c

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

RM = rm -f

HEADER = -I ./includes

.c.o:
	@${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${OBJS_BONUS}
	@ar rc ${NAME} ${OBJS} ${OBJS_BONUS}

bonus: ${OBJS_BONUS}
	@ar rc $(NAME) $(OBJS_BONUS)

all: ${NAME}

clean:
	@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	@${RM} ${NAME} ${OBJS_BONUS}

re: fclean all

re_all_bonus: fclean all bonus

.PHONY : all clean fclean re
