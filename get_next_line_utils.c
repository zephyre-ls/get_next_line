#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while(str[len] != '\0')
	{
		len++;
	}
	return(len);
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
	if (str == NULL || buff == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	while (buff[j] != '\0')
		dest[i++] = buff[j++];
	dest[i] = '\0';
	return (dest);
}
