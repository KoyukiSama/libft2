/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:10:56 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/30 16:24:02 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static char			**edge_case_strs(char **strs, char const *s);
static size_t		count_word(char const *s, char c);
static char			*cpy_word(char **strs, size_t i, char const *s, char c);
static char			**free_strs(char **strs, size_t count);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;

	if (!s)
		return (NULL);
	strs = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (c == '\0' && *s)
		return (edge_case_strs(strs, s));
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		s = cpy_word(strs, i, s, c);
		if (!strs[i])
			return (free_strs(strs, i));
		i++;
	}
	return (strs[i] = NULL, strs);
}

// '\0' check && malloc
static char	**edge_case_strs(char **strs, char const *s)
{
	strs[0] = ft_strdup(s);
	if (!strs[0])
		return (free(strs), NULL);
	strs[1] = NULL;
	return (strs);
}

// free strs
static char	**free_strs(char **strs, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(strs[i++]);
	if (strs)
		free(strs);
	return (NULL);
}

// counts words
static size_t	count_word(char const *s, char c)
{
	size_t	word_count;

	word_count = 0;
	if (!s)
		return (word_count);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		while (*s && *s != c)
			s++;
		word_count++;
	}
	return (word_count);
}

// returns the len of delim word
static char	*cpy_word(char **strs, size_t i, char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	strs[i] = ft_substr(s, 0, len);
	return ((char *)(s + len));
}

#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	char	**strs;
	(void) argc;

	const char *s = argv[1];
	char splitter = '\0';
	printf("word_count: [%li]\n-----------\n", count_word(s, splitter));
	// while (*s)
	// {
	// 	while (*s == splitter)
	// 		s++;
	// 	printf("%s, len:[%li]\n", s, get_word_len(s, splitter));
	// 	if (*s == '\0')
	// 		break;
	// 	while (*s && *s != splitter)
	// 		s++;
	// }
	//printf("\n");
	strs = ft_split(s, splitter);
	if (!strs)
		return (0);
	size_t	i = 0;
	while (strs[i])
	{
		printf("[%s]\n", strs[i]);
		free(strs[i]);
		i++;
	}
	printf("[%s]\n", strs[i]);
	free(strs);
	return (0);
}
