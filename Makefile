.PHONY : all clean fclean re

NAME = philo
FLAGS = -Wall -Wextra -Werror 
SRC = check_arg.c save_data.c init.c create_thread.c \
	  get_time.c free.c routine.c monitor.c put_msg.c main.c\


OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.c philo.h
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
