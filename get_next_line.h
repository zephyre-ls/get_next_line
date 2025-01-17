/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:10:24 by lduflot           #+#    #+#             */
/*   Updated: 2025/01/17 15:59:24 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
char	*ft_memcpy(char *line, char *stash, size_t len_line);
char	*ft_extract_line(char **stash);

#endif
