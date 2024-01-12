NAME = philo
PATH_SRCS = ./src/
PATH_TIME_SRCS = ./src/time/
PATH_UTILS = ./src/utils/
PATH_ACTIONS_SRCS = ./src/actions/
PATH_OBJS = ./objects/

SRCS = main.c \
	   free_table.c \
	   init_table.c \
	   loop_simulation.c \
	   monitor.c \
	   simulation.c \
	   validate_argv.c

ACTIONS_SRCS = eat.c \
			   rest.c \
			   think.c

TIME_SRCS = get_current_time.c \
			get_elapsed_time.c \
			msleep.c

UTILS = are_philos_full.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_isdigit.c \
		increase_meals_done.c \
		is_banquet_over.c \
		print_state.c

OBJS = ${SRCS:%.c=$(PATH_OBJS)%.o}
UTILS_OBJS = ${UTILS:%.c=$(PATH_OBJS)%.o}
TIME_OBJS = ${TIME_SRCS:%.c=$(PATH_OBJS)%.o}
ACTIONS_OBJS = ${ACTIONS_SRCS:%.c=$(PATH_OBJS)%.o}

INCLUDE = -I ./includes/
FLAGS = -Wall -Wextra -Werror -g3
LINKERS = -pthread

all: $(NAME)

$(NAME): $(OBJS) $(UTILS_OBJS) $(TIME_OBJS) $(ACTIONS_OBJS)
	@cc $(FLAGS) $(OBJS) $(UTILS_OBJS) $(TIME_OBJS) $(ACTIONS_OBJS) $(LINKERS) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "[SUCCESS] Object creation done!"

$(PATH_OBJS)%.o: $(PATH_UTILS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "[SUCCESS] Object creation done!"

$(PATH_OBJS)%.o: $(PATH_TIME_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "[SUCCESS] Object creation done!"

$(PATH_OBJS)%.o: $(PATH_ACTIONS_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "[SUCCESS] Object creation done!"

clean:
	@rm -rf $(PATH_OBJS)
	@echo "[SUCCESS] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[SUCCESS] Full clean done!"

re: fclean all

.PHONY: all clean fclean re
