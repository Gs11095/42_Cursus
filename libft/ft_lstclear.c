/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:15:11 by gsalvo            #+#    #+#             */
/*   Updated: 2021/01/22 16:49:57 by gsalvo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	t_list *pos;

	pos = *lst;
	if ((*lst) == 0)
		return ;
	while (pos)
	{
		temp = pos;
		pos = pos->next;
		ft_lstdelone(temp, del);
	}
	*lst = 0;
}
