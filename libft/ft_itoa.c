/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:51:00 by gsalvo            #+#    #+#             */
/*   Updated: 2021/01/20 14:52:29 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_length(long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		len++;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*numb;
	int		i;
	long	nb;

	nb = n;
	i = ft_length(n);
	if (!(numb = malloc(i + 1)))
		return (0);
	numb[i--] = 0;
	if (nb == 0)
	{
		*numb = 48;
		return (numb);
	}
	if (nb < 0)
	{
		*numb = 45;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		numb[i--] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (numb);
}
