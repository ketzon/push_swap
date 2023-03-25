BIN = bin
FLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = checker main division parse_input parse_sort push_swap quick_sort \
rotation utils
COMMAND_SRCS = clock push rot rrot swap utils

MANDATORY = push_swap
OBJ_BOTH = $(foreach src,$(SRCS),$(BIN)/$(src).o) $(foreach src,$(COMMAND_SRCS),$(BIN)/command_$(src).o)

NAME = $(MANDATORY)

ECHO = echo
RED = \033[31m
GRE = \033[32m
GRA = \033[37m
BLU = \033[34m
EOC = \033[0m

all: $(NAME)

bin/%.o: %.c
	@$(ECHO) "$(BLU)● Compiling $^ 🔧$(EOC)"
	@mkdir -p $(BIN)
	@gcc $(FLAGS) -c $^ -o $@

bin/command_%.o: command/%.c
	@$(ECHO) "$(BLU)● Compiling $^ 🔧$(EOC)"
	@mkdir -p $(BIN)
	@gcc $(FLAGS) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

$(NAME): $(OBJ_BOTH) $(BIN)/$(MANDATORY).o $(LIBFT)
	@$(ECHO) "$(GRE)● Adding libft to $@ ⚙️ $(EOC)"
	@$(ECHO) "$(GRE)● Compiling $@ ⚙️ $(EOC)"
	@gcc $(FLAGS) $(LIBFT) $^ -o $@

clean:
	@$(ECHO) "$(RED)● Removing /$(BIN) 📁$(EOC)"
	@rm -rf $(BIN)
	@make -C $(LIBFT_DIR) clean -s

fclean: clean
	@$(ECHO) "$(RED)● Removing binary ⚙️ $(EOC)"
	@rm -rf $(MANDATORY) $(BONUS)
	@make -C $(LIBFT_DIR) fclean -s

re: fclean all
