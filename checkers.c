/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:28:12 by agserran          #+#    #+#             */
/*   Updated: 2022/12/28 16:13:13 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	argv_checker(int argc)
{
	if (argc > 5)
	{
		perror("limit of orders exceeded.");
		exit(0);
	}
	if (argc < 5)
	{
		perror("invalid operation.");
		exit(0);
	}
}

int	complete_path_checker(char *cmd)
{
	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (1);
	}
	return (0);
}

void	pid_checker(int pid)
{
	if (pid < 0)
	{
		perror("FORK ERROR");
		exit(0);
	}
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
