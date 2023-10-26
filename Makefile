NAME = bin/philo

FLAGS = -Wall -Wextra -Werror -g

OBJ_DIR= obj

SRC_DIR = src

SRC_FILES = \
			main/main.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/main
	cc $(FLAGS) -c $< -o $@

run: all
	./$(NAME)

clean:
	rm -rf $(OBJ_DIR)/*.o

fclean: clean
	rm $(NAME)

re: fclean all
