/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:42:25 by gsalvo            #+#    #+#             */
/*   Updated: 2021/01/20 15:58:32 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	k;

	k = ft_strlen(s);
	while (k >= 0)
	{
		if (s[k] == (unsigned char)c)
			return ((char *)(s + k));
		k--;
	}
	return (NULL);
}
