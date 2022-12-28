/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patht.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:30:17 by agserran          #+#    #+#             */
/*   Updated: 2022/12/28 16:15:07 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*path_shorter(char **envp)
{
	int		i;
	char	*short_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			short_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			return (short_path);
		}
		i++;
	}
	return (NULL);
}

char	*get_path(char **envp, char *cmd)
{
	char	**paths;
	int		i;
	char	*path_cmd;
	char	*path;

	i = 0;
	paths = ft_split(path_shorter(envp), ':');
	if (complete_path_checker(cmd) == 1)
		return (cmd);
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		if (access(path_cmd, X_OK) == 0)
		{
			free(path);
			return (path_cmd);
		}
		free_two(path, path_cmd);
		i++;
	}
	free_it(paths);
	return (NULL);
}

void	free_it(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv[i]);
}

char	**cmd_split(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	return (cmd);
}

void	free_two(char *s1, char *s2)
{
	free(s1);
	free(s2);
}
