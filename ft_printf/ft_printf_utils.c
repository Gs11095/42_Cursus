/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:02:32 by gsalvo            #+#    #+#             */
/*   Updated: 2021/02/18 19:03:49 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sign(int *c)
{
	if ((*c % 2) == 0)
		*c = 1;
	else
		*c = -1;
}

int		ft_atoi(char *str)
{
	int i;
	int c;
	int res;

	res = 0;
	i = 0;
	c = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			c++;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10;
		res = res + (str[i] - '0');
		i++;
	}
	sign(&c);
	return (res * c);
}

int		ft_strlen(char *str)
{
	int i;

	if(!str)
		return(-1);
	i = 0;
	while(str[i])
		i++;
	return(i);
}

char	*ft_strdup(char *s1)
{
	size_t	x;
	char	*ptr;

	x = ft_strlen(s1) + 1;
	if (!(ptr = (char *)malloc(sizeof(char) * x)))
		return (NULL);
	ft_memcpy(ptr, s1, x);
	return (ptr);
}
