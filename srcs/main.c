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

int			main(int ac, char **av)
{
	t_wolf	w;
	
	check_ac(ac);
	if(parse(&w, av[1]) < 0)
	{
		ft_putendl("Map not correct");
		return 0;
	}
	my_mlx_init(&w, av[1]);
	mlx_hooks(&w);
	return (0);
}
