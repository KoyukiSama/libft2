/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:52:40 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/21 17:46:50 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include <stddef.h>
#include <stdlib.h>

static int	in_set(const char *set, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*ret_s;

	while (*s1 && in_set(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && in_set(set, s1[len - 1]))
		len--;
	ret_s = malloc(len + 1);
	if (!ret_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret_s[i] = s1[i];
		i++;
	}
	ret_s[i] = '\0';
	return (ret_s);
}

static int	in_set(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	(void) argc;
	printf("%s", ft_strtrim(argv[1], argv[2]));
}
