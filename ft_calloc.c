/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:57:20 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/21 15:09:23 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t n, size_t size)
{
	size_t	bytes;
	void	*s;

	if (n != 0 && n > SIZE_MAX / size)
		return (NULL);
	bytes = n * size;
	s = malloc(bytes);
	if (!s)
		return (NULL);
	return (ft_memset(s, 0, bytes));
}
