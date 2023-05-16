/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:38:26 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/16 16:38:47 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_line(int fd, char *str);
char	*take_line(char *str);
void	*gnl_calloc(int count, int size);
char	*gnl_strchr(char *str, int c);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(char *str);
char	*take_line(char *str);
char	*clean_buffer(char *buffer);

#endif
