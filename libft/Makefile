# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbesson@student.42.fr <marvin@42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 20:10:49 by fbesson@stude     #+#    #+#              #
#    Updated: 2022/12/17 18:29:36 by fbesson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

.DEFAUT_GOAL = all

OK_COLOR = \033[0;32m
NO_COLOR = \033[m

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \


BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \

OBJS = $(SRCS:.c=.o) 

OBJS_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	@echo "All .o deleted:$(OK_COLOR) OK!$(NO_COLOR)"
	@/bin/rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo "Archive deleted:$(OK_COLOR) OK!$(NO_COLOR)"
	@/bin/rm -f $(NAME)


re: fclean all
