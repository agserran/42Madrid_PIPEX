/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:46:43 by agserran          #+#    #+#             */
/*   Updated: 2022/12/22 15:47:55 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if ((size_t)ft_strlen((char *)s) < start)
	{
		str = malloc(1);
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(ft_min(ft_strlen((char *)s) - start, len) + 1);
	if (!str)
		return (0);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (s1[c] != '\0' && s2[c] != '\0' && (s1[c] == s2[c]))
	{
		c++;
	}
	if ((s1[c] != s2[c]) && (c < n))
		return ((unsigned char)s1[c] - (unsigned char)s2[c]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	l_s1;
	size_t	l_total;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	l_s1 = ft_strlen((char *)s1);
	l_total = l_s1 + ft_strlen((char *)s2);
	final = ft_calloc(sizeof(char), l_total + 1);
	if (final == NULL)
		return (NULL);
	i = 0;
	while (i < l_s1)
	{
		final[i] = s1[i];
		i++;
	}
	while (i < l_total)
	{
		final[i] = s2[i - l_s1];
		i++;
	}
	return (final);
}
