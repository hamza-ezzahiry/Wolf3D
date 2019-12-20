/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 11:43:56 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/02 16:13:51 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*cdst;
	char	tmp[65535];

	cdst = (char*)dst;
	i = 0;
	if (len > 65535)
		return (NULL);
	ft_memcpy(tmp, src, len);
	while (i < len)
	{
		cdst[i] = tmp[i];
		i++;
	}
	return (cdst);
}
