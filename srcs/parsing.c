/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <hamza.ezzahiry@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 01:13:28 by hezzahir          #+#    #+#             */
/*   Updated: 2019/12/18 01:18:22 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_color		new_color(int r, int g, int b)
{
	t_color c;

	c.b = b;
	c.g = g;
	c.r = r;
	return (c);
}

int			count_words(const char *s, char c)
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

int             ft_open(char *filename)
{
		int fd;

		if ((fd = open(filename, O_RDONLY)) == -1)
		{
				perror("wolf3d");
				exit(0);
		}
		return (fd);
}

int		is_everything_okey(char *tab)
{
	int	i;

	i = -1;
	while(i++ < 10)
		if(tab[i] == '0')
			return (-1);
	return (1);
}

void		make_free(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		ft_memdel((void **) &words[i]);
		i++;
	}
	ft_memdel((void **) &words);
}


void		check_resolution(char *line, t_map *map)
{
	char	**words;

	words = ft_strsplit(line, ' ');
	if(ft_strcmp(words[0], "R") == 0)
	{
		map->width = ft_atoi(words[1]);
		map->height = ft_atoi(words[2]);
		map->is_okey[0] = '1';
	}
	make_free(words);
}

void	ft_to_upper(char **s)
{
	int i;
	char	*tmp;

	i = 0;
	tmp = *s;
	while (tmp[i])
	{
		tmp[i] = ft_toupper(tmp[i]);
		i++;
	}
}

void		check_wall_textures(char *line, t_map *map)
{
	char	**words;

	words = ft_strsplit(line, ' ');
	ft_to_upper(&words[0]);
	if(ft_strcmp(words[0], "NO") == 0)
	{
		map->no = ft_strdup(words[1]);
		map->is_okey[1] = '1';
	}
	else if(ft_strcmp(words[0], "SO") == 0)
	{
		map->so = ft_strdup(words[1]);
		map->is_okey[2] = '1';
	}
	else if(ft_strcmp(words[0], "WE") == 0)
	{
		map->we = ft_strdup(words[1]);
		map->is_okey[3] = '1';
	}
	else if(ft_strcmp(words[0], "EA") == 0)
	{
		map->ea = ft_strdup(words[1]);
		map->is_okey[4] = '1';
	}
	make_free(words);
}

t_color		set_color(char *str)
{
	char	**res;
	t_color	c;

	res = ft_strsplit(str, ',');
	c = new_color(ft_atoi(res[0]), ft_atoi(res[1]), ft_atoi(res[2]));
	make_free(res);
	return (c);
}

void		check_composants(char *line, t_map *map)
{
	char	**words;

	words = ft_strsplit(line, ' ');
	if(ft_strcmp(words[0], "S") == 0)
	{
		map->s = ft_strdup(words[1]);
		map->is_okey[5] = '1';
	}
	else if (ft_strcmp(words[0], "F") == 0)
	{
		map->f = set_color(words[1]);
		map->is_okey[6] = '1';
	}
	else if (ft_strcmp(words[0], "C") == 0)
	{
		map->c = set_color(words[1]);
		map->is_okey[7] = '1';
	}
	make_free(words);
}



int		is_valide(char *l)
{
	int	i;

	i = 0;
	while(l[i])
	{
		if(l[i] != '0' && l[i] != '1' && l[i] != '2' && l[i] != 'E' &&
			l[i] != 'N' && l[i] != 'W' && l[i] != 'S')
			return (0);
		i++;
	}
	return (1);
}


int		check_map(char *line, t_map *map)
{
	char	*tmp;

	if(is_valide(line) && ((int) ft_strlen(line) == map->size))
	{
		tmp = ft_strjoin(map->grid, line);
		free(map->grid);
		map->grid = tmp;
	}
	else
	{
		free(line);
		ft_putendl("invalid map");
		exit(0);
	}
	return (1);
}

void		checker(char *line, t_map *map)
{
	t_line	l;

	l.nb_line = count_words(line, ' ');
	if(l.nb_line == 3)
	{
		check_resolution(line, map);
	}
	else if(l.nb_line == 1)
	{
		map->size =( map->size == 0) ? ft_strlen(line) : map->size;
		check_map(line, map);
	}
	else if(l.nb_line == 2)
	{
		check_wall_textures(line, map);
		check_composants(line, map);
	}
}

void	init_tab(char *tab)
{
	int	i;

	i = 0;
	while(i < 9)
	{
		tab[i] = '0';
		i++;
	}
}

int		check_grid(char *s)
{
	(void) s;
	return (1);
	return (0);
}

int     parse(t_wolf *w, char *s)
{
	char	*line;

	w->map.size = 0;
	init_tab(w->map.is_okey);
	w->fd = ft_open(s);
	w->map.grid = ft_strdup("");
	if (w->fd == -1)
		return (-1);
	while (get_next_line(w->fd, &line) > 0)
	{
		checker(line, &w->map);
		free(line);
	}
	if(check_grid(w->map.grid))
		w->map.is_okey[8] = '1';
	return is_everything_okey(w->map.is_okey);
}
