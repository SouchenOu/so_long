/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:22:26 by souchen           #+#    #+#             */
/*   Updated: 2021/11/16 15:54:14 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	j = ft_strlen(s);
	while (j >= i)
	{
		if ((unsigned char) s[j] == (unsigned char) c)
		{
			return ((char *) s + j);
		}
		j--;
	}
	return (NULL);
}
