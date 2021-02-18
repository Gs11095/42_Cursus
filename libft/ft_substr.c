/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:06:18 by gsalvo            #+#    #+#             */
/*   Updated: 2021/01/26 16:43:11 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		if (!(sub = malloc(1)))
			return (0);
		sub[0] = 0;
		return (sub);
	}
	if (!(sub = malloc(len + 1)))
		return (0);
	while (*s && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
