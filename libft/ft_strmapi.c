/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:09:27 by souchen           #+#    #+#             */
/*   Updated: 2021/11/18 22:50:25 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		length;
	int		i;

	if (!s)
	{
		return (NULL);
	}
	i = 0;
	length = ft_strlen(s);
	str = (char *) malloc (sizeof(char) * (length + 1));
	if (!str)
	{
		return (NULL);
	}
	while (length > i)
	{
		str[i] = f (i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
