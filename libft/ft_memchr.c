/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:15:20 by souchen           #+#    #+#             */
/*   Updated: 2021/11/17 18:44:36 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)memoryBlock;
	while (i < size)
	{
		if (str[i] == (unsigned char)searchedChar)
		{
			return ((void *) memoryBlock + i);
		}
		i++;
	}
	return (NULL);
}
