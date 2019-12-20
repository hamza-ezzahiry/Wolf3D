/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:21:06 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/08 10:50:10 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		isnegative(int n)
{
	int isnegative;

	isnegative = 0;
	if (n < 0)
	{
		isnegative = 1;
	}
	return (isnegative);
}

static	int		getlen(unsigned int nn, int n)
{
	int tmp;
	int len;

	len = 0;
	if (isnegative(n) == 1)
		len++;
	tmp = n;
	if (nn == 0)
		len = 1;
	while (tmp)
	{
		len++;
		tmp = tmp / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	unsigned int	nn;
	char			*tab;
	int				i;

	nn = (unsigned int)n;
	tab = malloc((getlen(nn, n) + 1));
	if (!tab)
		return (NULL);
	if (isnegative(n) == 1)
		nn = -nn;
	tab[0] = '-';
	tab[getlen(nn, n)] = '\0';
	i = getlen(nn, n) - 1;
	if (nn == 0)
		tab[i] = '0';
	while (nn && nn != 0)
	{
		if (nn < 10)
			tab[i] = nn + '0';
		tab[i--] = nn % 10 + '0';
		nn /= 10;
	}
	return (tab);
}
