/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <hamza.ezzahiry@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 21:25:31 by hezzahir          #+#    #+#             */
/*   Updated: 2019/05/14 22:21:53 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_count_words(const char *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			count += 1;
		if (s[i] != c && s[i + 1] == '\0')
			count += 1;
		i++;
	}
	return (count);
}

static	int			ft_word_len(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char				**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		nb_word;
	int		x;

	if (!s)
		return (NULL);
	x = 0;
	nb_word = ft_count_words(s, c);
	tab = (char **)malloc(sizeof(*tab) * (nb_word + 1));
	if (tab == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[x] = ft_strsub(s, 0, ft_word_len(s, c));
		if (tab[x] == NULL)
			return (NULL);
		s = s + ft_word_len(s, c);
		x++;
	}
	tab[x] = NULL;
	return (tab);
}
