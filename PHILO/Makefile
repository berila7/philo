NAME		=		philo

CC			=		cc
CFLAGS		=		-Wall -Wextra -Werror -Iincludes -fsanitize=address

SRCS		=		philo.c parsing.c parsing_utils.c free.c init.c \
					time.c routine.c routine_utils.c monitor.c 
OBJS		=		$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

philo/%.o: philo/%.c includes/philo.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re