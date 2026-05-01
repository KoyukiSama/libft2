/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:56:01 by kaclaes           #+#    #+#             */
/*   Updated: 2026/05/01 16:28:49 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (size == 0 || !dst)
		return (src_len);
	size--;
	if (size > src_len)
		size = src_len;
	while (size-- && *src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (src_len);
}
