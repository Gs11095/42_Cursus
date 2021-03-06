/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:13:57 by gsalvo            #+#    #+#             */
/*   Updated: 2021/01/20 18:14:04 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	len_s1;
	unsigned int	total;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	i = 0;
	total = len_s1 + ft_strlen(s2) + 1;
	newstr = malloc(total);
	if (!newstr)
		return (0);
	while (i < len_s1)
	{
		newstr[i] = s1[i];
		i++;
	}
	while (i < total - 1)
	{
		newstr[i] = s2[i - len_s1];
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}
