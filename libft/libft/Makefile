# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 13:44:46 by hoboutri          #+#    #+#              #
#    Updated: 2022/01/13 13:38:21 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = .


C_FILES = ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memset.c ft_isalnum.c ft_isascii.c\
		  ft_isprint.c ft_strlen.c ft_memcpy.c ft_toupper.c ft_tolower.c ft_atoi.c\
		  ft_strlcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
		  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c\
		  ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		  ft_putnbr_fd.c ft_striteri.c ft_itoa.c ft_strtrim.c ft_strmapi.c ft_split.c\

SRCS = $(addprefix $(SRC)/, $(C_FILES))

OBJS = $(SRCS:.c=.o) 

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBC = ar rcs 

RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) -I. -O2 -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
