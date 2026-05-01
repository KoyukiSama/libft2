/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:00:17 by kaclaes           #+#    #+#             */
/*   Updated: 2026/05/01 16:39:04 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*us;
	unsigned char	uc;

	if (!s)
		return (NULL);
	us = (unsigned char *) s;
	uc = (unsigned char) c;
	while (n > 0)
	{
		*us++ = uc;
		n--;
	}
	return (s);
}
