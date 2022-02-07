/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:47:12 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/04 00:40:42 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	isometric(float *x, float *y, int z,double angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	draw(float x,float y,float x1,float y1 ,t_fdf *map)
{
	float	deltax;
	float	deltay;
	int		pixels;
	float	pixelx;
	float	pixely;
	int		z;
	int		z1;

	z = map->vz[(int)y][(int)x];
	z1 = map->vz[(int)y1][(int)x1];
	//======== zoom =======//
	x *= map->zoom;
	y *= map->zoom;
	x1 *= map->zoom;
    y1 *= map->zoom;
	//======== 3D isometric =======//
	isometric(&x, &y, z, map->angle);
	isometric(&x1, &y1, z1, map->angle);
	//======== shifting =======//
	x += map->shiftx;
	y += map->shifty;
	x1 += map->shiftx;
	y1 += map->shifty;
	//======== draw line =======//
	deltax = x1 - x;
	deltay = y1 - y;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	map->color = (z) ? 0x16FC80 : 0xffffff;
	pixelx = x;
	pixely = y;
	while (pixels)
	{
		mlx_pixel_put(map->mlx,map->win,pixelx,pixely,map->color);
		pixelx += deltax;
		pixely += deltay;
		--pixels;	
	}	
}


void	drawingmap(t_fdf *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->haut)
	{
		x = 0;
		while (x < map->larg)
		{
			if (x < map->larg - 1)
				draw(x, y, x + 1, y, map);
			if (y < map->haut - 1)
				draw(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}