NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra 
SRCS = $(wildcard *.c)
OBJ = $(SRCS:%.c=%.o)

all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -lpthread $(OBJ) -o $(NAME)

clean : 
	rm -rf $(OBJ)
fclean : 
	rm -rf $(OBJ)
	rm -rf $(NAME)
re : fclean all


.phony : clean fclean all