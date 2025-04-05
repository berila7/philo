NAME		=		philo_bonus

CC			=		cc
FLAGS		=		-Wall -Wextra -Werror

SRCS_BONUS	=		PHILO_BONUS/philo_bonus.c
OBJS_BONUS	=		$(SRCS_BONUS:.c = .o)

all: $(NAME)

$(NAME): $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) -o $(NAME)

PHILO/%.o: PHILO/%.c includes/philo.h
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re