NAME = philo

FLAGS = -Wall -Wextra -Werror -g

LINKERS = -pthread

BIN = bin

OBJ_DIR= obj

SRC_DIR = src

SRC_FILES = \
			main/main.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(LINKERS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	cc $(FLAGS) -c $< -o $@

run: all
	$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
