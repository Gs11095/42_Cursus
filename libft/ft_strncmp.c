/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:53:35 by gsalvo            #+#    #+#             */
/*   Updated: 2021/01/25 15:21:25 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t k;

	k = 0;
	while (k < n)
	{
		if (s1[k] > s2[k])
		{
			return (((unsigned char*)s1)[k] - ((unsigned char*)s2)[k]);
		}
		if (s1[k] < s2[k])
		{
			return (((unsigned char*)s1)[k] - ((unsigned char*)s2)[k]);
		}
		if (s1[k] == '\0' && s2[k] == '\0')
		{
			return (0);
		}
		k++;
	}
	return (0);
}
