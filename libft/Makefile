# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 17:30:09 by tguimara          #+#    #+#              #
#    Updated: 2021/08/13 09:40:43 by tguimara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c

OBJECTS = ${SRC:.c=.o}

BONUS_OBJ = $(SRC_BONUS:.c=.o)

INCLUDE = libft.h

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
	@ranlib $(NAME)

%.o:%.c
	@gcc -Wall -Wextra -Werror -c $< -o $@ -I./

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME) *.o

bonus: $(NAME) $(BONUS_OBJ)
	@ar -rcs $(NAME) $(BONUS_OBJ)

re: fclean all
