/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:13:36 by lduflot           #+#    #+#             */
/*   Updated: 2025/01/17 16:55:17 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char *str, char *buff)
{
	int		i;
	int		j;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buff) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			dest[i] = str[i];
			i++;
		}
	}
	j = 0;
	while (buff[j] != '\0')
		dest[i++] = buff[j++];
	dest[i] = '\0';
	free(str);
	return (dest);
}

char	*ft_memcpy(char *line, char *stash, size_t len_line)
{
	char		*tmps;
	char		*tmpd;
	size_t		i;

	tmpd = line;
	tmps = stash;
	i = 0;
	if (line == NULL && stash == NULL)
		return (NULL);
	while (i < len_line)
	{
		tmpd[i] = tmps[i];
		i++;
	}
	return ((char *)line);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
