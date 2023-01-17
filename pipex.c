/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:35:52 by agserran          #+#    #+#             */
/*   Updated: 2023/01/17 15:53:19 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	firts_child(int fd[2], char *cmd, char **envp, char *infile)
{
	char	**splited_cmd;
	char	*path;
	int		in;

	in = open(infile, O_RDONLY);
	if (in == -1)
	{
		perror("invalid infile");
		exit(0);
	}
	close(fd[READ_END]);
	dup2(in, STDIN_FILENO);
	splited_cmd = cmd_split(cmd);
	path = get_path(envp, splited_cmd[0]);
	printf("%s\n", path);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	if (execve(path, splited_cmd, envp) == -1)
	{
		free_it(splited_cmd);
		ft_putstr("command not found.1");
		exit(0);
	}
}

static void	last_child(int fd[2], char *cmd, char **envp, char *exitfile)
{
	char	**splited_cmd;
	char	*path;
	int		out;

	close(fd[WRITE_END]);
	out = open(exitfile, O_RDWR | O_CREAT | O_TRUNC, 0666);
	splited_cmd = cmd_split(cmd);
	path = get_path(envp, splited_cmd[0]);
	printf("%s\n", path);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	dup2(out, STDOUT_FILENO);
	close(out);
	if (execve(path, splited_cmd, envp) == -1)
	{
		free_it(splited_cmd);
		ft_putstr("command not found.");
		exit(0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	argv_checker(argc);
	pipe(fd);
	pid = fork();
	pid_checker(pid);
	if (pid == 0)
		firts_child(fd, argv[2], envp, argv[1]);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			last_child(fd, argv[3], envp, argv[4]);
		}
		else
		{
			close(fd[READ_END]);
			close(fd[WRITE_END]);
		}
	}
	waitpid(pid, NULL, 0);
	return (0);
}
