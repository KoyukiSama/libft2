/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:10:56 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/29 16:18:00 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static char			**free_strs(char **strs, size_t count);
static size_t		get_word_len(char const *s, char delim);
static size_t		count_word(char const *s, char c);
static char const	*get_next_word(char const *s, char delim);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	j;
	size_t	str_len;

	strs = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (s[0] == '\0')
		return (strs[0] = NULL, strs);
	if (c == '\0')
	{
		strs[0] = ft_strdup(s);
		if (!strs[0])
			return (free(strs), NULL);
		return (strs[1] = NULL, strs);
	}
	if (*s == c)
		s = get_next_word(s, c);
	i = 0;
	while (*s)
	{
		str_len = get_word_len(s, c);
		strs[i] = malloc(str_len + 1);
		if (!strs[i])
			return (free_strs(strs, i));
		j = 0;
		while (j < str_len)
			strs[i][j++] = *s++;
		strs[i][j] = '\0';
		s = get_next_word(s, c);
		i++;
	}
	strs[i] = NULL;
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

	if (s[0] == '\0')
		return (0);
	if (c == '\0')
		return (1);
	word_count = 0;
	if (*s == c)
		s = get_next_word(s, c);
	while (*s)
	{
		s = get_next_word(s, c);
		word_count++;
	}
	return (word_count);
}

// returns the len of delim word
static size_t	get_word_len(char const *s, char delim)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != delim)
		len++;
	return (len);
}

// return char * to next word
static char const	*get_next_word(char const *s, char delim)
{
	while (*s != delim && *s)
		s++;
	while (*s == delim)
		s++;
	return (s);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(int argc, char **argv)
// {
// 	const char	*s;
// 	char	**strs;
// 	(void) argv;
// 	(void) argc;

// 	s = "tripouille";
// 	char splitter = 0;
// 	// printf("word_count: [%li]\n\n", count_word(s, argv[2][0]));
// 	// while (*s)
// 	// {
// 	// 	printf("%s, len:[%li]\n", s, get_word_len(s, argv[2][0]));
// 	// 	s = get_next_word(s, argv[2][0]);
// 	// }
// 	// printf("\n");
// 	strs = ft_split(s, splitter);
// 	if (!strs)
// 		return (0);
// 	size_t	i = 0;
// 	while (strs[i])
// 	{
// 		printf("[%s]\n", strs[i]);
// 		free(strs[i]);
// 		i++;
// 	}
// 	printf("[%s]\n", strs[i]);
// 	free(strs);
// 	return (0);
// }
