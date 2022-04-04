/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:38:28 by souchen           #+#    #+#             */
/*   Updated: 2021/11/17 21:48:29 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *destination, void *source, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	src = (unsigned char *)source;
	dest = (unsigned char *)destination;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (src < dest)
	{
		src = source + n - 1;
		dest = destination + n - 1;
		while (n-- > 0)
			*dest-- = *src--;
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (destination);
}
