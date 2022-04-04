/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:42:23 by souchen           #+#    #+#             */
/*   Updated: 2021/11/19 13:54:29 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_intlen(int x)
{
	int	len;

	len = 0;
	if (x <= 0)
	{
		len = 1;
	}
	while (x != 0)
	{
		x = x / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int x)
{
	long int	nbr;
	int			len;
	char		*str;
	int			resu;

	nbr = x;
	len = ft_intlen(nbr);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	if (nbr == 0)
		str[len - 1] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * (-1);
	}
	str[len] = '\0';
	while (nbr > 0)
	{
		resu = (nbr % 10);
		str[(len--) - 1] = resu + '0';
		nbr = nbr / 10;
	}
	return (str);
}
