#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

char	*get_next_line(int fd);
char	*ft_find_newline(char *str);
char	*ft_readline(char *stash, int fd);
char	*ft_strjoin(char *str, char *buff);
int		ft_strlen(const char *str);
char	*ft_strdup(char *str);
char	*ft_extract_line(char **stash);

#endif
