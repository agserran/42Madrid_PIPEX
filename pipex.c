#include "pipex.h"


int	main(int argc,char **a<F12>rgv, char **argv2)
{
	int	fd[2];
	int	fd2;
	int	pid;

	pipe(fd1);/*comunica dos procesos*/

	pid = fork();

	if (pid == 0)/*child1 1st command*/
	{
		close(fd1[READ_END]);

		dup2(fd1[WRITE_END], STDOUT_FILENO);
		close(fd1[WRITE_END]);

		execve()/*TO DO GET_PATHNAME*/;
	}
	else
	{
		close(fd1[WRITE_END]);
		pid = fork();
		if (pid == 0)/*child2 2nd command*/
		{
			fd2 = open(FILE_NAME, /*FLAGS TO CREATE A FILE FOR OUTPUT*/);
			dup2(fd1[READ_END], STDIN_FILE);
			close(fd1[READ_END]);

			dup2(fd2, STDOUT_FILENO);
			execve();/*TO DO*/
		}
		else/*father process*/
			close(fd1[READ_END]);
	}
}
