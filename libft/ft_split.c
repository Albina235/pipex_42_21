/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:46:27 by evalorie          #+#    #+#             */
/*   Updated: 2021/10/21 18:39:25 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

static int	ft_countwords(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c)
			|| (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_countlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*ft_strndup(char *str, int size)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc((size + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	s2[size] = '\0';
	while (i < size)
	{
		s2[i] = *str;
		str++;
		i++;
	}
	return (s2);
}

static char	**ft_dop(char *s, char **buff, int count, char c)
{
	int	i;

	i = 0;
	while (*s != '\0' && i < count)
	{
		if (*s != c)
		{
			buff[i] = ft_strndup(s, ft_countlen(s, c));
			if (buff[i] == NULL)
			{
				while (i > 0)
					free(buff[--i]);
				free(buff);
				return (NULL);
			}
			i++;
			s = (char *)s + (ft_countlen(s, c) - 1);
		}
		s++;
	}
	buff[count] = NULL;
	return (buff);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**buff;
	int		i;

	buff = NULL;
	if (s)
	{
		count = ft_countwords((char *)s, c);
		i = 0;
		buff = (char **)malloc((count + 1) * sizeof(char *));
		if (buff == NULL)
			return (NULL);
		buff = ft_dop((char *)s, buff, count, c);
	}
	return (buff);
}
