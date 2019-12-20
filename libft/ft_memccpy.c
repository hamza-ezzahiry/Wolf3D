/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:03:07 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/02 15:24:25 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t				i;
	unsigned char		cc;

	cc = (char)c;
	i = 0;
	while (i < n)
	{
		((unsigned char*)s1)[i] = ((unsigned char*)s2)[i];
		if (cc == ((unsigned char*)s2)[i])
		{
			((unsigned char*)s1)[i] = ((unsigned char*)s2)[i];
			return ((unsigned char*)s1 + i + 1);
		}
		i++;
	}
	return (NULL);
}
