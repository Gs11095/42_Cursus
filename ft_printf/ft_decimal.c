/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:00:42 by gsalvo            #+#    #+#             */
/*   Updated: 2021/02/18 19:00:46 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_decimal(va_list args, t_list *list)
{
	char *str_numb;
	int x;

	x = va_arg(args, int);
	//printf("x: %d\n", x);

	if(x == 0)
		list->num_0 = 1;
	if(x < 0)
		list->num_m = 1;
	if(list->num_m == 1) //&& list->flag_minus == 1)
	{
		x *= -1;
		list->width--;
	}
	str_numb = ft_itoa(x);
//	printf("%s\n", str_numb);
	list->type = 'd';
//	ft_listprint(list);
	ft_putstr(str_numb, list);
	free(str_numb);
}
