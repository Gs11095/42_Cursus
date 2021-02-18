/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:34:28 by gsalvo            #+#    #+#             */
/*   Updated: 2021/01/20 15:56:48 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (!src && !dst)
		return (0);
	while (i < len)
	{
		if (dst < src)
			((char *)dst)[i] = ((char *)src)[i];
		else
			((char *)dst)[len - i - 1] = ((char *)src)[len - i - 1];
		i++;
	}
	return (dst);
}
