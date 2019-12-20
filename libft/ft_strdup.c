/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:33:16 by hezzahir          #+#    #+#             */
/*   Updated: 2018/11/08 17:45:52 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cn;
	char	*ch;
	int		i;

	cn = (char *)str;
	i = 0;
	ch = (char*)malloc((ft_strlen(cn) + 1) * sizeof(char));
	if (!ch)
	{
		ch = NULL;
		return (ch);
	}
	while (cn[i] != '\0')
	{
		ch[i] = cn[i];
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
