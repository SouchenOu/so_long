/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:29:53 by souchen           #+#    #+#             */
/*   Updated: 2021/11/17 23:33:27 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *string, int nub, size_t size)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)string;
	i = 0;
	while (size > 0)
	{
		str[i] = (unsigned char)nub;
		i++;
		size--;
	}
	return (string);
}
