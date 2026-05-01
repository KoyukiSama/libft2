/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:36:02 by kaclaes           #+#    #+#             */
/*   Updated: 2026/05/01 16:24:33 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

//    The  strchr()  and  strrchr()
//    functions return a pointer to
//    the matched character or NULL
//    if  the  character   is   not
//    found.   The terminating null
//    byte is  considered  part  of
//    the  string,  so that if c is
//    specified  as   '\0',   these
//    functions return a pointer to
//    the terminator.				(from man page strrchr)
char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*us;
	unsigned char		uc;

	if (!s)
		return (NULL);
	us = (const unsigned char *) s;
	uc = (unsigned char) c;
	while (*us != uc && *us)
		us++;
	if (*us == uc)
		return ((char *) us);
	return (NULL);
}
