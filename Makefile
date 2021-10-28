NAME= pipex

all : $(NAME)

$(NAME):
		gcc *.c -o $@ -L. -lft -fsanitize=address
		./$@ infile "grep usr" "wc -l" outfile
		rm $@

fclean :
		rm -rf pipex