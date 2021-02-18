/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:02:10 by gsalvo            #+#    #+#             */
/*   Updated: 2021/02/18 19:02:14 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
#define	FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#define BASE10 "0123456789"
#define base16 "0123456789abcdef"
#define BASE16 "0123456789ABCDEF"

typedef struct s_option
{
    int flag_minus;
    int flag_zero;
    int width;
    int dot;	     // to know if there is precision
    int precision;   // initially set as -1 instead of 0
    int num_0; // if number is zero
    int num_m;	     // is number negative?
    char type;
	int	count;

 } t_list;

int				ft_printf(const char *input, ...);
void			ft_putchar(char c, t_list *list);
void			ft_putnbr(int nb, t_list *list);
void			ft_putstr(char *str, t_list *list);
int				ft_checkflag(const char *input, int i, t_list *list, va_list args);
void			ft_listinit(t_list *list);
void			ft_listprint(t_list *list);
int				ft_atoi(char *str);
void			sign(int *c);
void			ft_putchar_mod(char c, t_list *list);
int				ft_strlen(char *str);
int				set_precision(char *str, t_list *list, int s);
int				conv_ex(int nb);
void			ft_decimal(va_list args, t_list *list);
char			*ft_itoa(int n);
char			*fill(char *str, int n, unsigned int sign, unsigned int k);
unsigned int	ft_sign(int n);
unsigned int	ft_nbdigit(int n);
char			*ft_strdup(char *s1);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_printzero(t_list *list, int i, int s);
int				ft_size_number_uns_diffbase(size_t n, char *base);
char			*ft_itoa_base(size_t n, char *base);
void			ft_unsigned(va_list args, t_list *list);
void			ft_hexadecimal(va_list args, t_list *list);
void			ft_address(va_list args, t_list *list);


#endif
