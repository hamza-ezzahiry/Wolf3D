/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 13:30:45 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/03 17:49:00 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	s;
	int		i;
	size_t	ret;

	i = 0;
	s = size;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (s <= len_dst)
		return (s + len_src);
	else
	{
		ret = len_dst + len_src;
		while (src[i] != '\0' && len_dst + 1 < s)
		{
			dst[len_dst] = src[i];
			len_dst++;
			i++;
		}
		dst[len_dst] = '\0';
	}
	return (ret);
}
