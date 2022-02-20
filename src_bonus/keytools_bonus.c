/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytools_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:33:02 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/20 15:33:07 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf_bonus.h"

void	destroyall(t_fdf *map)
{
	mlx_destroy_image(map->mlx, map->img);
	mlx_destroy_window(map->mlx, map->win);
	free(map->igs);
	free(map);
	exit(0);
}

int	keycodex(int keycode)
{
	if (keycode == 32 || keycode == 2
		|| (keycode > 122 && keycode < 127)
		|| (keycode < 18 && keycode > 11)
		|| (keycode < 36 && keycode > 33))
		return (1);
	else
		return (0);
}

void	otherswitch(int keycode, t_fdf *map)
{
	if (keycode == 34)
	{
		map->anglex = 0.523599;
		map->angley = 0.523599;
		map->isomet = 1;
	}
	if (keycode == 35)
		map->isomet = 0;
	if (keycode == 13)
		map->elevat += 1;
	if (keycode == 12)
		map->elevat -= 1;
	if (keycode == 16)
		map->anglex += 0.1;
	if (keycode == 17)
		map->anglex -= 0.1;
}

int	key_release(int keycode, t_fdf *map)
{
	if (keycodex(keycode))
	{
		if (keycode == 32)
			map->zoom += 1;
		if (keycode == 2)
			map->zoom -= 1;
		if (keycode == 126)
			map->shifty -= 10;
		if (keycode == 125)
			map->shifty += 10;
		if (keycode == 123)
			map->shiftx -= 10;
		if (keycode == 124)
			map->shiftx += 10;
		if (keycode == 15)
			map->angley += 0.1;
		if (keycode == 14)
			map->angley -= 0.1;
		otherswitch(keycode, map);
		reimg(map);
	}
	else if (keycode == 53)
		destroyall(map);
	return (0);
}

int	closes(t_fdf *map)
{
	destroyall(map);
	return (0);
}
