/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <hamza.ezzahiry@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:15:33 by hezzahir          #+#    #+#             */
/*   Updated: 2019/12/21 23:18:03 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		my_mlx_init(t_wolf *w, char *s)
{
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, WIDTH, HEIGHT, s);
	w->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
}

void		mlx_hooks(t_wolf *w)
{
	mlx_hook(w->win, 2, 0, key_press, w);
	//mlx_hook(f->win, 4, 0, mouse_press, f);
	//mlx_hook(f->win, 6, 0, mouse_move, f);
	mlx_loop(w->mlx);
}
