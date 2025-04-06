NAME = philo
LIBFT_DIR = lib/libft
LIBFT = libft

CC = cc
CFLAGS = -Wall -Werror -Wextra 
SRCS = $(wildcard *.c)
SIM_OBJ = $(SRCS:%.c=%.o)
OBJ = $(addprefix obj/, $(SIM_OBJ))
all : $(LIBFT) $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -L ./$(LIBFT_DIR) -lft -lpthread $(OBJ) lib/libft/libft.a -o $(NAME)

$(LIBFT) : 
	make -C $(LIBFT_DIR)

obj/%.o : %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)
	rm -rf obj
	make clean -C $(LIBFT_DIR)

fclean : 
	rm -rf $(OBJ)
	rm -rf obj
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all


.phony : clean fclean all
