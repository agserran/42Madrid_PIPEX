#include "pipex.h"

void	argv_checker(int	argc)
{
	if (argc > 4)
	{
		perror("limit of orders exceeded, put two commands and the output file");
		exit(0);
	}
}
int	complete_path_checker(char *cmd)
{
	if (cmd[0] == '/')
	{
		if(access(cmd, X_OK) == 0)
			return (1);
	}
	return (0);
}
