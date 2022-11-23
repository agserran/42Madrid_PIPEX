#include "pipex.h"

static void	firts_child(int fd[2], char *cmd, char **envp)
{
	char	**splited_cmd;
	char	*path;

	close(fd[READ_END]);
	splited_cmd = cmd_split(cmd);
	path = get_path(envp, cmd);
	printf("%s\n", path);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	if(execve(path, splited_cmd, envp) == -1)
	{
		free_it(splited_cmd);
		ft_putstr("command not found.1");
		exit(0);
	}
}

static void	last_child(int fd[2], char *cmd, char **envp)
{
	int	i;
	char	**splited_cmd;
	char	*path;

	close(fd[WRITE_END]);
	i = 0;
	splited_cmd = cmd_split(cmd);
	path = get_path(envp, cmd);
	printf("%s\n", path);
	dup2(fd[READ_END], STDIN_FILENO);
	if(execve(path, splited_cmd, envp) == -1)
	{
		free_it(splited_cmd);
		ft_putstr("command not found.");
		exit(0);
	}

}

int	main(int argc,char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	pipe(fd);/*comunica dos procesos*/

	pid = fork();
	if(pid < 0)
	{
		perror("ERROR FORK");
		exit(0);
	}
	(void)argc;
	if (pid == 0)
	{
		firts_child(fd, argv[1], envp);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			last_child(fd, argv[2], envp);
		}
		else
			close(fd[READ_END]);
	}
	open("outfile", O_CREAT | O_TRUNC | O_WRONLY);
}
