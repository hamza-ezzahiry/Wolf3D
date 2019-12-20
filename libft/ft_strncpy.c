/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:13:26 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/02 16:06:35 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*str;
	size_t		i;

	str = (char *)src;
	i = -1;
	while (++i < len && str[i])
		dst[i] = str[i];
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
