/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:05:57 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/28 17:58:19 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	tmp_str[11];
	size_t	i;
	long	nbr;
	int		negative;

	nbr = n;
	negative = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
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
	write(fd, tmp_str + i + 1, 10 - i);
}

// #include <stdlib.h>
// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	ft_putnbr_fd(atoi(argv[1]), 1);
// }
