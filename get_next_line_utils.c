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
	int		lens1;
	int		lens2;
	char	*dest;

	lens1 = ft_strlen(str);
	lens2 = ft_strlen(buff);
	dest = malloc(sizeof(char) * (lens1 + lens2 + 1));
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
	if (str != NULL)
		free(str);
	return (dest);
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
