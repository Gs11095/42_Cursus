/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:03:59 by gsalvo            #+#    #+#             */
/*   Updated: 2021/02/18 19:04:02 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c, t_list *list)
{
	write(1, &c, 1);
	list->count++;
//	ft_listprint(list);
}

void ft_putchar_mod(char c, t_list *list)
{
	if(list->flag_minus == 1)
	{	
	
		ft_putchar(c, list);
		list->width--;
		while(list->width > 0)
		{
			ft_putchar(' ', list);
			list->width--;
		}
		return;
	}
	else if (list->flag_zero == 1) 
	{
		list->width--;
		while(list->width > 0)
		{
			ft_putchar('0', list);
			list->width--;
		}
	}
	else
	{
		list->width--;
		while(list->width > 0)
		{
			ft_putchar(' ' , list);
			list->width--;
		}
	}
	ft_putchar(c, list);
}

void	ft_putstr(char *str, t_list *list)
{
	int i;
	int s;

	if(!str)
		str = "(null)";

	i = 0;
	if(list->flag_minus == 1)
	{	
		s = 0;
		if (list->num_m)
			ft_putchar('-', list);
		while(i < set_precision(str, list, s))
		{
			ft_putchar(str[i], list);
			i++;
			s = 1;
		}
		s = 2;
		list->width -= set_precision(str, list, s);
		while(list->width > 0)
		{
			ft_putchar(' ', list);
			list->width--;
		}	
	}
	else
	{	
		s = 3;
		if(list->num_m && list->flag_zero && list->precision <= -1) //list->flag_zero
			ft_putchar('-', list);
		list->width -= set_precision(str, list, s);
		while(list->width > 0)
		{
			if(list->flag_zero && list->precision <= -1)
				ft_putchar('0', list);
				
			else
				ft_putchar(' ', list);
			list->width--;
		}
		if (list->type =='p')
		{
			ft_putchar('0',list);
			ft_putchar('x',list);
		}
		if(list->num_m && list->flag_zero && list->precision > -1) //list->flag_zero
			ft_putchar('-', list);
		if(list->num_m &&  !list->flag_zero) //(!list->flag_zero || 
			ft_putchar('-', list);
		s = 0;
		while( i < set_precision(str, list, s))
		{ 
			ft_putchar(str[i], list);
			i++;
			s = 1;
		}
	}
}

int		set_precision(char *str, t_list *list, int s)
{
	int i;

	i = ft_strlen(str);
	if(list->type == '0')
	{
		if(list->dot == 2)
			return(0);
		if(list->precision <= -1)
			return(i);
		if(list->precision < i)
			return(list->precision);
		else
			return(i);
	}
//	if(list->type == 'd')
	else
	{
		if(list->precision == - 1 || list->precision <= i)
		{
			if(list->num_0 == 1 && list-> precision == 0) //fin qui tutto bene
				i--;									// fin qui tutto bene
			if(list->num_0 == 1 && list->dot == 2) //modifica che espode
				i--;
			return(i);
		}
		if(list->precision > i && (s == 0 || s == 2 || s == 3))
		{
			
			return(ft_printzero(list, i, s));
		}
		else
			return (i);
	}

}

int	ft_printzero(t_list *list,int i, int s)
{
	int x;
	
	x = list->precision - i;
	if(s == 0)
	{
		while(x)
		{
			ft_putchar('0', list);
			x--;
		}
		//ft_listprint(list);
		return(i);
	}
	if( s == 3)
	{
		return (list->precision);
	}
	else
		return(x + i);
}
