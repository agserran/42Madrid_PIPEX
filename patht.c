#include "pipex.h"

void	get_path(char *env, char *cmd)
{
	char	*envpath;
	char	**paths;
	int	i;
	char	*cmdpath;

	i = 0;
	paths = ft_split(envpath, ":");
	
	while(paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		free(path);
		i++;
	}
	freeit(paths);
}

char	**free_it(char *arg)
{
	char	**arg_split;

	arg_split = ft_split(cmd, " ");
	return (cmd2);
}
