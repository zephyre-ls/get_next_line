/*Fonction ok = MALLOC, FREE, READ
Return = Contenue de la ligne lue, NULL si rien d autre a lire ou error
Descriptor = Ecrire unefonction qui retourne une ligne lue depuis un descripteur de fichier
GNL_utils = fonction supplementaires necessaire a la realisation de GNL
Compilation = cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
Buffer = (tampon en francais) est une zone de memoire utilise pour sotcker temporairement des donnes pendant qu elle sont transferer entredeux endroits 
INTERDIT = libft, ft lseek, variable globales
VARIABLE STATIQUE = variable qui conserve sa valeur entre plusieurs appels de fonctions c a d qu elle ne perd pas sa valeur quand la fonction se termine 

ssize_t read(int fd, void *buf, size_t count);

int fd= 0 entrée standard (stdin, clavier)
				1 sortie standard (stdout l ecran)
				2 erreur standar (stderr)

open action selon type d'ouverture =
O_RDONLY = lecture seule
O_WRONLY = ecriture seule
O_RDWR = both 

void *buf = pointeur vers une zone de memoire ou les donnes lu seronts stocke 
size_t count= nombre max d octet a lire 
lire dans un fichier et stocke dans une variable, a une static donc si je redemande ( byte va prendre apres les 5 premiers byte demander la premiere fois. (Donc comporte une static)

Difference entre size_t et ssize_t = 
	_ size_t = type non signé (unsigned) = que des valeurs positives 
		ssize_t = type signé les deux valeurs, dans le cas de read utilisations de ssize-t puise renvoie erreur si jamais n a pas reussis a lire le fichier 
exemple file = Hello$
							good bye
buff = après appel = Hello
byte 5
return = 5
*/

#include "get_next_line.h"

// Cherche \n ou fin du fichier
char	*ft_find_newline(char *str)
{
	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

//lit les données et les stocke dans str.
char	*ft_readline(char *stash, int fd)
{
	char	*buff;
	char	*newline;
	int		byte_read; //nombre d octet lu a chaque appel de read
	
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));//stockage temporaire des données lu
	if (buff == NULL)
		return (NULL);
	byte_read = 1;
	newline = ft_find_newline(stash);
	while (newline == NULL && byte_read > 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free (buff);
			return (NULL);
		}
		if (byte_read > 0)
		{
			buff[byte_read] = '\0';
			stash = ft_strjoin(stash, buff); //join les nouvelles donnes lues au donnes deja lu
			if (stash == NULL)
			{
				free(buff);
				return (NULL);
			}
			newline = ft_find_newline(stash);
		}
	}
	free(buff);
	return (stash);
}

char	*ft_extract_line(char **stash)
{
	char	*line;
	char	*new_line;
	char	*tmp_stash;
	int		len_line;
	int		i;

	new_line = ft_find_newline(*stash);
	if (new_line == NULL)
	{
		line = *stash;
		*stash = NULL;
		return (line);
	}
	len_line = (new_line - *stash);
	len_line = len_line + 1;
	line = malloc(sizeof(char) * (len_line + 1));
	if (line != NULL)
	{
		i = 0;
		while ((*stash)[i] != '\0' && i < (len_line - 1))
		{
			line[i] = (*stash)[i];
			i++;
		}
	//ft_strncpy(line, *stash, len_line);
		line[i] = '\0';
		tmp_stash = ft_strdup(*stash + len_line);
		free(*stash);
		*stash = tmp_stash;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash; //stash = stock, reserve, cachette.
	char				*line; //buffer pour lire les données
	
	if (fd < 0 || BUFFER_SIZE <= 0) //fichier invalide ou taille buff invalide
		return (NULL);
	stash = ft_readline(stash, fd);
	if (stash == NULL)
		return (NULL);
	line = ft_extract_line(&stash);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;  // zone memoire pour stock les donnes
	
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (line == NULL)
		return (-1);
	while (line != NULL)
	{
		printf("Lecture: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
