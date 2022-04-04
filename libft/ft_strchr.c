/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:59:44 by souchen           #+#    #+#             */
/*   Updated: 2021/11/19 15:19:30 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int ch)
{
	int	i;

	i = 0;
	while ((unsigned char)s[i] != (unsigned char)ch)
	{
		if (s[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return ((char *) s + i);
}
