/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 06:03:20 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/16 23:54:22 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	fcompare(const char *haystack, const char *needle, int ilen)
{
	int i;

	i = 0;
	while (*haystack && *needle)
	{
		if (i >= ilen)
			return (0);
		if (*haystack != *needle)
			return (0);
		haystack++;
		needle++;
		i++;
	}
	if (!(*needle))
		return (1);
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int ilen;
	int i;

	i = 0;
	ilen = (int)len;
	if (haystack == needle)
		return ((char*)haystack);
	if (ft_strlen(haystack) == 0 && ft_strlen(needle) == 0)
		return ((char*)haystack);
	if (ft_strlen(haystack) == 0)
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (*haystack)
	{
		if ((*haystack == *needle) && fcompare(haystack, needle, ilen) == 1)
			return ((char*)haystack);
		haystack++;
		ilen--;
	}
	return (NULL);
}
