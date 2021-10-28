#include <stdio.h>
#include "pipex.h"

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


void	first_process(int *fd, char **gv, char **en)
{
	int	infile;
	char	**cmd;
	char	*abs_path;

	infile = open(gv[1], O_RDWR);
	cmd = ft_split(gv[2], ' ');
	if (!cmd)
		exit(0);
	abs_path = path(cmd[0], en);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);

	if(execve(abs_path, cmd, en) == -1)
		exit(0);
}

void	second_process(int *fd, char **gv, char **en)
{
	int	outfile;
	char	**cmd;
	char	*abs_path;

	outfile = open(gv[4], O_RDWR | O_TRUNC);
	cmd = ft_split(gv[3], ' ');
	if (!cmd)
		exit(0);
	abs_path = path(cmd[0], en);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	if(execve(abs_path, cmd, en) == -1)
		exit(0);
}


int main(int gc, char **gv, char **en)
{

	int	i;
	int	fd[2];
	int	pid;
	if (gc != 5)
		print_error();

	pipe(fd);

	pid = fork();
	if (!pid)
	{
		first_process(fd, gv, en);
	}
	else
	{
		second_process(fd, gv, en);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}