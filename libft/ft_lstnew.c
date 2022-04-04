/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:27:24 by souchen           #+#    #+#             */
/*   Updated: 2021/11/18 13:00:47 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nv;

	nv = (t_list *)malloc(sizeof(t_list));
	if (nv == NULL)
	{
		return (NULL);
	}
	nv->content = content;
	nv->next = NULL;
	return (nv);
}
