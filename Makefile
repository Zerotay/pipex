NAME= pipex

all : $(NAME)

$(NAME):
		make -C ./libft all bonus
		gcc *.c -Wall -Werror -Wextra -o $@ -L./libft -lft -I./libft -I.

clean:
	make -C ./libft fclean

fclean : clean
		rm -rf pipex

re: fclean all

.PHONY: clean fclean all re
