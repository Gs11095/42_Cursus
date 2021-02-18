/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:33:02 by gsalvo            #+#    #+#             */
/*   Updated: 2021/01/20 15:59:11 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	k;

	k = 0;
	while (k <= ft_strlen(str))
	{
		if (str[k] == (unsigned char)c)
			return (char *)(str + k);
		k++;
	}
	return (NULL);
}
