/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:44:21 by agserran          #+#    #+#             */
/*   Updated: 2022/12/22 18:05:01 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/wait.h>

# define READ_END 0
# define WRITE_END 1

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *str);
char	*get_path(char **envp, char *cmd);
void	free_it(char **argv);
char	*ft_strjoin(char const *s1, char const *s2);
char	**cmd_split(char *argv);
void	argv_checker(int argc);
int		complete_path_checker(char *cmd);
void	pid_checker(int pid);
void	free_two(char *s1, char *s2);

#endif
