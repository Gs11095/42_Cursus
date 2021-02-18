/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:00:27 by gsalvo            #+#    #+#             */
/*   Updated: 2021/02/18 19:00:32 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_address(va_list args, t_list *list)
{
	char *str_numb;
	size_t x;

	x = va_arg(args, size_t);
	if(x == 0)
		list->num_0 = 1;	
	str_numb = ft_itoa_base( x, base16);
//	printf("Indirizzo con atoi:%s\n",str_numb);
	list->type = 'p';
	if(list->flag_minus == 1)
	{
		ft_putchar('0', list);
		ft_putchar('x', list);
	}
	list->width -= 2;
	ft_putstr(str_numb, list);


	free(str_numb);

}
