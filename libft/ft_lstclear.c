/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 07:58:51 by souchen           #+#    #+#             */
/*   Updated: 2021/11/18 17:44:51 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*pp;

	p = *lst;
	while (p != NULL)
	{
		pp = p->next;
		ft_lstdelone(p, del);
		p = pp;
	}
	*lst = NULL;
}
