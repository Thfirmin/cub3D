/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs50.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:22:18 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 00:22:21 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CS50_H
# define CS50_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Mains
char	cs_get_char(char *prompt);
char	*cs_get_str(char *prompt);
char	*cs_get_line(char *prompt);
int		cs_get_int(char *prompt);

// utils
char	*cs_strjoin(char *s1, char *s2);
int		cs_putstr_fd(char *str, int fd);
int		cs_strlen(char *str);

#endif
