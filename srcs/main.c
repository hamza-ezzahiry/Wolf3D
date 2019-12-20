/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <hamza.ezzahiry@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 00:12:01 by hezzahir          #+#    #+#             */
/*   Updated: 2019/11/16 14:53:28 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		check_ac(int ac)
{
	if (ac != 2)
	{
		show_usage();
		exit(0);
	}
}

void            show_usage(void)
{
        ft_putendl("Usage : ./wolf3d {map name}");
}

/*
void		my_mlx_init(t_wolf *w, char *s)
{
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, WIDTH, HEIGHT, s);
	w->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
}
int key_press(int key, t_wolf *w)
{
	return (1);
}

void		mlx_hooks(t_wolf *w)
{
	mlx_hook(w->win, 2, 0, key_press, w);
	mlx_hook(f->win, 4, 0, mouse_press, f);
	mlx_hook(f->win, 6, 0, mouse_move, f);
	mlx_loop(w->mlx);
}*/
int			main(int ac, char **av)
{
	t_wolf	w;
	
	check_ac(ac);
	if(parse(&w, av[1]) == -1)
		exit(-1);
	// my_mlx_init(w, av[1]);
	// mlx_hooks(w);
	return (0);
}
