/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 03:44:39 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/06 00:56:01 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int			i;
	int			j;
	int			length;

	i = 0;
	j = 0;
	length = ft_strlen(to_find);
	if (length == 0)
		return ((char*)str);
	while (str[i])
	{
		while (to_find[j] == str[i + j])
		{
			if (j == length - 1)
				return ((char*)str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
