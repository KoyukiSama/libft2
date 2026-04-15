/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:51:59 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/15 15:15:51 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*usrc;
	unsigned char	*udest;

	if (!dest && !src && n > 0)
		return (dest);
	usrc = (const unsigned char *) src;
	udest = (unsigned char *) dest;
	while (n)
	{
		*udest++ = *usrc++;
		n--;
	}
	return (dest);
}
