/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:04:11 by gsalvo            #+#    #+#             */
/*   Updated: 2021/02/18 19:04:14 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_unsigned(va_list args, t_list *list)
{
	char *str_numb;
	int x;

	x = va_arg(args, unsigned int);
	if(x == 0)
		list->num_0 = 1;
	str_numb = ft_itoa_base((unsigned int)x, BASE10);
	list->type = 'd';
	ft_putstr(str_numb, list);


	free(str_numb);
}
