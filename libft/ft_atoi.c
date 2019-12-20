/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 10:21:12 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/05 11:45:53 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		sign;
	char	*rr;

	result = 0;
	sign = 1;
	rr = (char*)str;
	while (*rr == '\t' || *rr == '\v' || *rr == '\f'
			|| *rr == '\r' || *rr == ' ' || *rr == '\n')
		rr++;
	if (*rr == '-')
	{
		sign = -1;
	}
	if (*rr == '+' || *rr == '-')
		rr++;
	while (*rr >= '0' && *rr <= '9')
	{
		result = result * 10 + *rr - 48;
		rr++;
	}
	return (result * sign);
}
