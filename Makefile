NAME= pipex

all : $(NAME)

$(NAME):
		gcc *.c -o $@ -L. -lft
		./$@ infile "grep bin" "wc -l" outfile
		rm $@

fclean :
		rm -rf pipex