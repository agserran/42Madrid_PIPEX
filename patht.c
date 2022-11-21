#include "pipex.h"

char	*path_shorter(char **env)
{
	int		i;
	char	*short_path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5))
			{
				short_path = ft_substr(env[i], 5, ft_strlen(env[i]));
				return (short_path);
			}
		i++;
	}
	return (NULL);
}

char	*get_path(char **env, char **cmd)
{
	char	**paths;
	int		i;
	char	**path_cmd;
	char	**path;
	char	**splited_cmd;

	i = 0;
	paths = ft_split(path_shorter(env) , ":");
	
	while(paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		free(path);
		if(access(path_cmd, X_OK) == 0)
			return(path_cmd[i]);
		i++;
	}
	freeit(paths);
	return (NULL);
}

char	**free_it(char *arg)
{
	char	**arg_split;

	arg_split = ft_split(cmd, " ");
	return (cmd2);
}
