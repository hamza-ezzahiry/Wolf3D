/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 21:17:36 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/03 12:30:01 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*ss2;

	ss2 = (char*)s2;
	i = ft_strlen((const char *)s1);
	j = 0;
	while (ss2[j])
	{
		s1[i] = ss2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
