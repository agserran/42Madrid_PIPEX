#include "pipex.h"

static char	*path_shorter(char **envp)
{
	int		i;
	char	*short_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5))
			{
				short_path = ft_substr(envp[i], 5, ft_strlen(env[i]));
				return (short_path);
			}
		i++;
	}
	return (NULL);
}

char	*get_path(char **envp, char *cmd)
{
	char	**paths;
	int	i;
	char	**path_cmd;
	char	**path;
	char	**splited_cmd;

	i = 0;
	paths = ft_split(path_shorter(envp) , ":");
	
	while(paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		free(path);
		if(access(path_cmd, X_OK) == 0)
			return(path_cmd[i]);
		i++;
	}
	free_it(paths);
	return (NULL);
}

void	free_it(char **argv)
{
	int	i;

	i = 0;

	while(*argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv[i]);
}

char	**cmd_split(char *argv)
{
	char	**cmd;

	cmd = ft_split(cmd, " ");
	return (cmd);
}
