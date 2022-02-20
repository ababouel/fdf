/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:37:51 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/20 16:24:45 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	destroyall(t_fdf *map)
{
	mlx_destroy_image(map->mlx, map->img);
	mlx_destroy_window(map->mlx, map->win);
	free(map->igs);
	free(map);
	exit(0);
}

int	key_release(int keycode, t_fdf *map)
{
	if (keycode == 53)
		destroyall(map);
	return (0);
}

int	closes(t_fdf *map)
{
	destroyall(map);
	return (0);
}
