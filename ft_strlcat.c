/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:27:44 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/21 11:27:52 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// 	The  strlcat()  function  ap‐
//  pends   the    NUL-terminated
//  string src to the end of dst.
//  It will append at most size -
//  strlen(dst)  -  1 bytes, NUL-
//  terminating the result. (from man page strlcat)
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	rem;

	dst_len = 0;
	while (dst_len < size && dst[dst_len])
	{
		dst_len++;
	}
	src_len = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (dst_len == size)
		return (src_len + dst_len);
	dst += dst_len;
	rem = size - dst_len - 1;
	while (rem-- > 0 && *src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
