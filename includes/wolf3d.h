/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <hamza.ezzahiry@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:09:10 by hezzahir          #+#    #+#             */
/*   Updated: 2019/11/09 04:24:00 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../libft/libft.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 700
# define HEIGHT 700

typedef struct	s_plot
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
}				t_plot;

typedef struct	s_point
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}				t_point;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef	struct	s_map
{
	int		width;
	int		height;
	int		size;
	char	*grid;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	t_color	f;
	t_color	c;
	char	is_okey[9];
}				t_map;

typedef struct	s_wolf
{
	void	*win;
	void	*mlx;
	void	*img;
	int		fd;
	t_map	map;
}				t_wolf;

typedef struct	s_line
{
	int		nb_line;
	int		trouve;
}				t_line;

/*
** functions
*/
void			show_usage(void);
void			check_ac(int ac);
void			check_av(char *str, t_wolf *w);
int				parse(t_wolf *w, char *s);
void			ft_to_upper(char **s);
int				key_press(int key);
void			my_mlx_init(t_wolf *w, char *s);
void			mlx_hooks(t_wolf *w);

#endif
