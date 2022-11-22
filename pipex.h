#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define	READ_END	1
#define	WRITE_END	0

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *str);

#endif
