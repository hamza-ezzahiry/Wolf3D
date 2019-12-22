/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <hamza.ezzahiry@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:46:59 by hezzahir          #+#    #+#             */
/*   Updated: 2019/12/22 21:10:51 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	bresenham(t_point line, t_wolf *w)
{
	t_plot	plot;

	plot.dx = abs(line.x1 - line.x0);
	plot.sx = line.x0 < line.x1 ? 1 : -1;
	plot.dy = -abs(line.y1 - line.y0);
	plot.sy = line.y0 < line.y1 ? 1 : -1;
	plot.err = plot.dx + plot.dy;
	while (1)
	{
		mlx_pixel_put(w->mlx, w->win, line.x0 + 400, line.y0 + 100, 0xFFFFFF);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		plot.e2 = 2 * plot.err;
		if (plot.e2 >= plot.dy)
		{
			plot.err += plot.dy;
			line.x0 += plot.sx;
		}
		if (plot.e2 <= plot.dx)
		{
			plot.err += plot.dx;
			line.y0 += plot.sy;
		}
	}
}
