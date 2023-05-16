/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:37:06 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/14 10:25:28 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *s, char set);

static int		ft_setjumper(char const *s, char set);

static int		ft_count_words(char const *s, char set);

// split a file into pieces
char	**ft_split(const char *s, char c, t_mem **mem)
{
	char	**split;
	int		words;
	int		i;
	int		start;
	int		len;

	if (!s)
		return (0);
	words = ft_count_words(s, c);
	split = ft_malloc((words + 1) * sizeof(char *), "ft_split", mem);
	if (!split)
		return (0);
	i = -1;
	start = 0;
	while (++i < words)
	{
		if ((!start && *s == c) || start)
			start += ft_setjumper((s + start), c);
		len = ft_wordlen((s + start), c);
		*(split + i) = ft_substr(s, start, len, mem);
		start += len;
	}
	*(split + words) = (void *)0;
	return (split);
}

// Count subword separated by set character
static int	ft_count_words(char const *s, char set)
{
	int	words;
	int	i;

	if (!*s)
		return (0);
	words = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != set)
		{
			words ++;
			while (*(s + i) && *(s + i) != set)
				i ++;
		}
		else
			while ((*(s + i)) && (*(s + i) == set))
				i ++;
	}
	return (words);
}

// Position pointer in begin of next subword separated by set character
static int	ft_setjumper(char const *s, char set)
{
	int	i;

	i = 0;
	while ((*(s + i) == set) && (*(s + i)))
		i ++;
	return (i);
}

// Count subwordlenght terminated by set or null character
static size_t	ft_wordlen(char const *s, char set)
{
	size_t	len;

	len = 0;
	while (s && (*(s + len) && (*(s + len) != set)))
		len ++;
	return (len);
}
