#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	(void)argc;

	path = get_path(envp, argv[2]);
	printf("%s\n", path);
	return 0;
}

