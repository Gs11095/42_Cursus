/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:01:55 by gsalvo            #+#    #+#             */
/*   Updated: 2021/02/18 19:02:00 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print(const char *input, va_list args)
{
	int i;
	t_list *list;
	int ret;

	
	if(!(list = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	list->count = 0;
	i = 0;
	while (input[i])
	{
		ft_listinit(list);
		if (input[i] == '%' && input[i + 1])// && input[i + 1] != '%') 
		{
			i++;
			i = ft_checkflag(input, i, list, args);
		//	ft_listprint(list);
			if ((input[i] == 'd' || input[i] == 'i')) //|| input[i] == 'p' 
				ft_decimal(args, list);
			else if (input[i] == 'u')
				ft_unsigned(args, list);
			else if (input[i] == 'x' || input[i] == 'X')
			{
				if(input[i] == 'X')
					list->type = 'X';
				ft_hexadecimal(args, list);
			}
			else if (input[i] == 'p')
				ft_address(args, list);
			else if (input[i] == 'c')
				ft_putchar_mod(va_arg(args, int), list);
			else if (input[i] == '%')
				ft_putchar_mod('%', list);
			else if (input[i] == 's')
				ft_putstr(va_arg(args, char *), list);
			else
				break;
		}
	//	else if (input[i] == '%' && input[i + 1] && input[i + 1] == '%')
	//		ft_putchar(input[++i], list);
		else
			ft_putchar(input[i], list);
		i++;
	}
	ret = list->count;
	free(list);
	return (ret);
}

int ft_checkflag(const char *input, int i, t_list *list, va_list args)
{
	while(input[i] == '-' || input[i] == '0' || input[i] == '*' || (input[i] > '0' && input[i] <= '9') || input[i] == '.')
	{
		if(input[i] ==  '-')
			list->flag_minus = 1;
		else if(input[i] == '0')
			list->flag_zero = 1;
		else if(input[i] > '0' && input[i] <= '9')
		{
			list->width = ft_atoi((char *)input + i);
			while(input[i + 1] >= '0' && input[i + 1] <= '9')
				i++;
		}
		else if(input[i] == '*')
			list->width = va_arg(args, int);		
		else if(input[i] == '.')
		{	
			list->dot = 1;
			i++;
			if(input[i] == '*')
				list->precision = va_arg(args, int);
			else if (input[i] >= '0' && input[i] <= '9')
			{
				list->precision = ft_atoi((char *)input + i);
				while(input[i + 1] >= '0' && input[i + 1] <= '9')
					i++;
			}
			else
			{
				list->dot = 2;
				break;
			}
		}
		i++;
	//	printf("input: %c\n", input[i]);
	}
	if (list->flag_zero == 1 && list->flag_minus == 1)
			list->flag_zero = 0;
	if (list->width < 0)
	{
		list->flag_minus = 1;
		list->width *= -1;
	}
	return(i);
	
}

void	ft_listinit(t_list *list)
{
	list->flag_minus = 0;
	list->flag_zero = 0;
	list->width = 0;
	list->dot = 0;
	list->precision = -1;
	list->num_0 = 0;
	list->num_m = 0;
	list->type = '0';
}

void	ft_listprint(t_list *list)
{
	printf("------------------------\n\n");
	printf("flag_minus: %d\n",list->flag_minus);
	printf("flag_zero: %d\n",list->flag_zero);
	printf("width: %d\n",list->width);
	printf("dot: %d\n",list->dot);
	printf("precision: %d\n",list->precision);
	printf("num_0: %d\n",list->num_0);
	printf("num_m: %d\n",list->num_m);
	printf("type: %c\n",list->type);
	printf("count: %d\n",list->count);
	printf("------------------------\n\n");
}


int	ft_printf(const char *input, ...)
{
	va_list args;
	int i;
//	int count;

	va_start(args, input);

	i = ft_print(input, args);

	va_end(args);
	return (i);
}
