/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:50:29 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/14 10:36:26 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include "includes/ft_printf.h"

// Struct
typedef struct s_mem
{
	void			*ptr;
	char			*context;
	struct s_mem	*next;
}					t_mem;

// is
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);

// to
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n, t_mem **mem);

// str
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s1, t_mem **mem);
char	*ft_substr(char const *s, unsigned int start, size_t len, t_mem **mem);
char	*ft_strjoin(char const *s1, char const *s2, t_mem **mem);
char	*ft_strtrim(char const *s1, char const *set, t_mem **mem);
char	**ft_split(char const *s, char c, t_mem **mem);
void	ft_striteri(char *s, void (*f) (unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char), t_mem **mem);

// mem
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t count, size_t size, char *context, t_mem **mem);

// Put
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);

// Garbage Collector
void	ft_memadd_back(t_mem **mem, t_mem *new);
void	ft_memadd_front(t_mem **mem, t_mem *new);
t_mem	*ft_memnew(void	*ptr, char *context);
void	*ft_malloc(size_t size, char *context, t_mem **mem);
void	*ft_calloc(size_t count, size_t size, char *context, t_mem **mem);
void	ft_free(void *ptr, t_mem **mem);
void	ft_freel(t_mem **mem);
void	ft_sumary(t_mem *mem);
int		ft_memsize(t_mem *mem);

#endif
