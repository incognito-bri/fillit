NAME = fillit

SRCS =	build_board.c \
	build_piece.c  \
	exit_free.c \
	fillit.c \
	find_spot.c \
	linked_list.c \
	place_remove.c \
	read.c \
	setup.c \

OBJS = $(SRCS:.c=.o)

INCL = fillit.h

LIBFT = libft/

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -I ./libft/ -L. libft/libft.a
clean: 
	@rm -rf $(OBJS)
	make clean -C $(LIBFT) 
fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT) 
re: fclean all

.PHONY: re fclean clean all
