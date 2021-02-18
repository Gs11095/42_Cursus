/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:45:07 by gsalvo            #+#    #+#             */
/*   Updated: 2021/01/20 16:34:03 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	k;

	if (!src && !dest)
		return (0);
	k = ft_strlen(src);
	if (size == 0)
	{
		return (k);
	}
	k = 0;
	while (src[k] && k < size - 1)
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = '\0';
	k = 0;
	while (src[k])
	{
		k++;
	}
	return (k);
}
