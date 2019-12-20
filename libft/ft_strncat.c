/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 12:51:44 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/03 14:57:01 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;
	int		x;
	char	*ss2;

	x = (int)n;
	ss2 = (char*)s2;
	i = ft_strlen((const char *)s1);
	j = 0;
	while (ss2[j] && j < x)
	{
		s1[i] = ss2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
