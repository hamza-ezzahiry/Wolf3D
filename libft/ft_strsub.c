/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:38:14 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/05 19:22:54 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	tab = malloc((int)len + 1);
	if (!tab)
		return (NULL);
	while (i < (int)len)
	{
		tab[i] = s[(int)start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}
