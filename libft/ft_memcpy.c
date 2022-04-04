/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:18:01 by souchen           #+#    #+#             */
/*   Updated: 2021/11/17 21:15:51 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t		i;
	char		*t1;
	const char	*t2;

	i = 0;
	t1 = (char *) destination;
	t2 = (char *) source;
	if (!(t1) && !(t2))
		return (NULL);
	while (i < size)
	{
		t1[i] = t2[i];
		i++;
	}
	return (destination);
}
