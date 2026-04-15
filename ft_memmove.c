/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:25:37 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/15 15:51:48 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*usrc;
	unsigned char		*udest;

	if (!dest && !src && n > 0)
		return (dest);
	usrc = (const unsigned char *) src;
	udest = (unsigned char *) dest;
	if (udest > usrc && usrc + n > udest)
	{
		usrc += n - 1;
		udest += n - 1;
		while (n)
		{
			*udest-- = *usrc--;
			n--;
		}
	}
	else
	{
		while (n)
		{
			*udest++ = *usrc++;
			n--;
		}
	}
	return (dest);
}
