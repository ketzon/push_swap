NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = command/rot.c command/rrot.c command/utils.c command/push.c command/swap.c push_swap.c parse_input.c utils.c checker.c quick_sort.c parse_sort.c division.c rotation.c \
	main.c command/clock.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

