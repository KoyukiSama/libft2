/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:11:58 by kaclaes           #+#    #+#             */
/*   Updated: 2026/05/01 16:27:02 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s1[i] == s2[i])
		i++;
	return ((int)((unsigned char) s1[i] - (unsigned char) s2[i]));
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	printf("%i\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
// 	printf("%i\n", strncmp(argv[1], argv[2], atoi(argv[3])));
// }
