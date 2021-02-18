/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:24:23 by gsalvo            #+#    #+#             */
/*   Updated: 2021/01/22 18:15:46 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dest;

	len = 0;
	while (s1[len])
		len++;
	if (!(dest = (char*)malloc((len * sizeof(char)) + 1)))
		return (0);
	len = 0;
	while (s1[len])
	{
		dest[len] = s1[len];
		len++;
	}
	dest[len] = 0;
	return (dest);
}
