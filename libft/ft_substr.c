/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:42:14 by souchen           #+#    #+#             */
/*   Updated: 2021/11/18 18:57:23 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:58:54 by souchen           #+#    #+#             */
/*   Updated: 2021/11/18 18:30:40 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*test;
	size_t	j;
	size_t	i;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s + start))
	{
		len = ft_strlen(s + start);
	}
	test = (char *) malloc ((len + 1) * sizeof(char));
	if (test == NULL)
	{
		return (NULL);
	}
	while (i < ft_strlen(s) && j < len)
	{
		test[j++] = s[i++];
	}
	test[j] = '\0';
	return (test);
}
