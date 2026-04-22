/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:59:30 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/22 19:24:37 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char	tmp_str[12];
	size_t	i;
	long	nbr;
	int		negative;

	nbr = n;
	negative = 0;
	if (n == 0)
		return (ft_strdup("0"));
	i = 11;
	tmp_str[i--] = '\0';
	if (nbr < 0)
	{
		negative = 1;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		tmp_str[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (negative)
		tmp_str[i--] = '-';
	return (ft_strdup(tmp_str + i + 1));
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	(void) argc;

// 	printf("%s", ft_itoa(atoi(argv[1])));
// }
