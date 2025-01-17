    Get Next Line

Projet qui permet de lire une ligne à la foid d'un fichier. 
Utilisation de read avec des appels successifs.

Fonctions utilés

    get_next_line  char	*get_next_line(int fd);
Fonction principale qui permet de lire une ligne à la fois d'un fichier. 
Elle utilise read pour obtenir des données du fichier et les stocke dans un buffer.
Buffer = zone mémoire utilisée pour stocker temporairement des données. 
La fonction renvoie la ligne lue à chaque appel.

    read : ssize_t read(int fd, void *buf, size_t count);
Lecture d'un bloc de donné à partir d'un fichier. Elle remplie notre buffer. Dans get_next_line read est utilisé pour lire 
jusqu'à la prochaine occurence du caractere de fin de ligne ('\n'), ou jusqu'à la fin du fichier.

    char	*ft_find_newline(char *str);
Recherche la premiere occurene ici fin de ligne (\n). Utilisation dans get_next_line pour détecter la fin de la ligne.

    char	*ft_strdup(char *str);
Duplique une chaine de caractere et ainsi créer une nouvelle chaîne à partir d'une partie du buffer. Vu que chaque ligne doit etre extraite et analysé séparément.

    char	*ft_strjoin(char *str, char *buff);
Concatène deux chaînes de caractères et est utilisée pour joindre le contenu du buffer avec la chaîne déjà lue, formant ainsi une ligne complète au fur et à mesure des lectures successives.

      char	*ft_extract_line(char **stash)
Extrait les lignes complete du buffer de donnéees. Elle cherche ou se termine la ligne et alloue la memoire pour la ligne extraite. Ensuite, elle modifie le stash pour ne garder que le reste des données pas encore lus, ainsi la lecture peut continuer.
 
    Variables Statiques - static char *stash;
Permettent de conserver le même état entre plusieurs appels de la fonction. Elles stockent la partie restante du buffer d'une lecture précédente. 
Ce qui permet de continuer la lecture là où elle s'est arrêtée lors de l'appel suivant. 
Nécessaire car read ne lit que par blocs, et les lignes peuvent s'étendre sur plusieurs appels à read.
    
    Open
Permet d'ouvrir un fichier en lecture avant d'utiliser read.
