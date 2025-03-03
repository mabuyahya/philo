NAME = philo
LIBFT_DIR = lib/libft
LIBFT = libft

CC = cc
CFLAGS = -Wall -Werror -Wextra -g 
SRCS = $(wildcard *.c)
OBJ = $(SRCS:%.c=%.o)

all : $(LIBFT) $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -L ./$(LIBFT_DIR) -lft -lpthread $(OBJ) lib/libft/libft.a -o $(NAME)

$(LIBFT) : 
	make -C $(LIBFT_DIR)

clean : 
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean : 
	rm -rf $(OBJ)
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all


.phony : clean fclean all
