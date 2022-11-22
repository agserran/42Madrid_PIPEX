#include "pipex.h"

static void	firts_child(int fd, char *cmd, char **envp)
{
	int	i;
	char	**splited_cmd;
	char	*path;

	close(fd[READ_END]);
	i = 0;
	splited_cmd = cmd_split(cmd);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	path = get_path(envp, cmd);
	close(fd[WRITE_END]);
	if(execve(path, splited_cmd, envp) == -1)
	{
		free_it(splited_cmd);
		ft_putstr("command not found.");
		exit(0);
	}
}

static void	last_child(int fd, char *cmd, char **envp)
{
	int	i;
	char	**splited_cmd;
	char	*path;

	close(fd[WRITE_END]);
	i = 0;
	splited_cmd = cmd_split(cmd);
	dup2(fd, STDOUT_FILENO);
}

int	main(int argc,char **argv, char **envp)
{
	int	fd;
	int	fd2;
	int	pid;

	pipe(fd);/*comunica dos procesos*/

	pid = fork();

	if (pid == 0)/*child1 1st command*/
	{
		firts_child(fd, argv[2], envp);
	}
	else
	{
		close(fd1[WRITE_END]);
		pid = fork();
		if (pid == 0)/*child2 2nd command*/
		{
			fd2 = open(FILE_NAME, /*FLAGS TO CREATE A FILE FOR OUTPUT*/);
			dup2(fd1[READ_END], STDIN_FILENO);
			close(fd1[READ_END]);

			dup2(fd2, STDOUT_FILENO);
			execve();/*TO DO*/
		}
		else/*father process*/
			close(fd1[READ_END]);
	}
}
