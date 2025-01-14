
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

#define BUFFER_SIZE 300

// Cherche \n ou fin du fichier

char	*ft_find_newline(char *str)
{
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
	char *newline;
	int	byte_read; //nombre d octet lu a chaque appel de read
	
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));//stockage temporaire des données lu
	newline = ft_find_newline(stash);
	byte_read = read(fd, buff, BUFFER_SIZE);
	byte_read = 1;
	while (newline == NULL && byte_read > 0)
	{
		if (byte_read > 0)
		{
			buff[byte_read] = '\0';
			stash = ft_strjoin(stash, buff); //join les nouvelles donnes lues au donnes deja lu
		}
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash; //stash = stock, reserve, cachette.
	char	*line; //buffer pour lire les données 

	stash = NULL;
	line = 0;

	if (fd < 0 || BUFFER_SIZE <= 0) //fichier invalide ou taille buff invalide
		return (NULL);
	stash = ft_readline(line, fd);
	if (stash == NULL)
	{
		free(line);
		return (NULL);
	}
	return(stash);
}

int	main(void)
{
	int fd;
	char *line;  // zone memoire pour stock les donnes 

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
