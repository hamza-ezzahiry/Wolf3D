/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:35:48 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/02 17:45:12 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;

	i = 0;
	cc = (char)c;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == cc)
		{
			return ((unsigned char*)s + i);
		}
		i++;
	}
	return (NULL);
}
