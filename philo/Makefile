NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_usleep.c  init.c  main.c  main_utilites.c  rotene.c  taking_forks.c  threads_utilites.c  utilites.c
SIM_OBJ = $(SRCS:%.c=%.o)
OBJ = $(addprefix obj/, $(SIM_OBJ))
all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -lpthread $(OBJ) -o $(NAME)

obj/%.o : %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)
	rm -rf obj

fclean : 
	rm -rf $(OBJ)
	rm -rf obj
	rm -rf $(NAME)

re : fclean all


.phony : clean fclean all
