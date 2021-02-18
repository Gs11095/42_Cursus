/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:45:14 by gsalvo            #+#    #+#             */
/*   Updated: 2021/01/22 18:00:49 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pos;

	pos = *lst;
	if (new == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	while (pos->next)
		pos = pos->next;
	pos->next = new;
}
