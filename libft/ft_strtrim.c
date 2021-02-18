/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:41:13 by gsalvo            #+#    #+#             */
/*   Updated: 2021/01/20 14:43:05 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		isinboth(char a, char const *set)
{
	while (*set)
	{
		if (a == *set)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	size_t		i;
	size_t		j;
	char		*copy;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	while (isinboth(s1[i], set) && s1[i])
		i++;
	while (isinboth(s1[len - 1], set) && i < len)
		len--;
	if (!(copy = malloc(len - i + 1)))
		return (0);
	while (i < len)
		copy[j++] = s1[i++];
	copy[j] = 0;
	return (copy);
}
