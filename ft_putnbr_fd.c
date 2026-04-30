/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:05:57 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/30 17:51:34 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

static size_t	fill_str(char *tmp_str, long nbr);

void	ft_putnbr_fd(int n, int fd)
{
	char	tmp_str[11];
	size_t	offset;
	
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	offset = fill_str(tmp_str, n);
	write(fd, tmp_str + offset + 1, 10 - offset);
}

static size_t	fill_str(char *tmp_str, long nbr)
{
	int		negative;
	size_t	i;

	negative = 0;
	i = 10;
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
	return (i);
}

// #include <stdlib.h>
// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	ft_putnbr_fd(atoi(argv[1]), 1);
// }
