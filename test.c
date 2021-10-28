#include <stdio.h>
#include "pipex.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}


char	*path(char *gv, char **en)
{
	int		i;
	char	**split;
	char	*slash;
	char	*singlepath;

	i = 0;
	while (ft_strncmp(en[i], "PATH", 4))
		i++;
	split = ft_split(en[i] + 5, ':');
	i = -1;
	while(split[++i])
	{
		slash = ft_strjoin(split[i], "/");
		singlepath = ft_strjoin(slash, gv);
		if (!access(singlepath, F_OK))
			return (singlepath);
	}
	return (0);
}

void	print_error(void)
{
	exit(0);
}


int	first_process(int *fd, char **gv, char **en)
{
	int	infile;
	char	**cmd;
	char	*abs_path;

	cmd = ft_split(gv[2], ' ');
	if (!cmd)
		exit(0);
	abs_path = path(cmd[0], en);
	printf("i want %s\n", abs_path);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	// execve(abs_path, cmd, en);
	if(execve(abs_path, cmd, en) == -1)
		exit(0);
}

int main(int gc, char **gv, char **en)
{

	int	i;
	char **tmp1;
	char **tmp2;
	int	fd[2];
	int	pid;
	int infile;
	int	outfile;

	if (gc != 5)
		print_error();
	tmp1 = ft_split(gv[2], ' ');
	tmp2 = ft_split(gv[3], ' ');
	infile = open(gv[1], O_RDWR  | O_CREAT, 0777);
	outfile = open(gv[4], O_RDWR | O_TRUNC);

	pipe(fd);

	pid = fork();
	if (!pid)
	{
		first_process(fd, gv, en);
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execve(path(tmp1[0], en), tmp1, en);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[1]);
		execve(path(tmp2[0], en), tmp2, en);
	}
	free(tmp1);
	free(tmp2);
	close(infile);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	return (0);


}


// void	print_error(void)
// {
// 	exit(0);
// }

// int	main(int gc, char **gv, char **en)
// {
// 	int	pid;
// 	int fd[2];
// 	int	infile;
// 	int	outfile;

// 	if (gc != 5)
// 		print_error();
// 	infile = open(gv[1], O_RDWR);
// 	if (!infile)
// 		print_error();
// 	outfile = open(gv[4], O_RDWR | O_TRUNC);
// 	if (!outfile)
// 		print_error();
// 	pipe(fd);
// 	pid = fork();
// 	if (!pid)
// 	{
// 		dup2(infile, STDIN_FILENO);
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		ex
// 	}
// 	else
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		dup2(outfile, STDOUT_FILENO);
// 		close(fd[1]);
// 		ex
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	close(infile);
// 	close(outfile);
// }