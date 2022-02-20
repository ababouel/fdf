/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:10:00 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/20 16:09:31 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	addvect(t_vect3 *v, float x, float y, int color)
{
	v->x = x;
	v->y = y;
	v->color = color;
}

void	isometric(float *x, float *y, int z, t_fdf *map)
{
	float	p;

	p = *x;
	*x = (p - *y) * cos(map->anglex);
	*y = (p + *y) * sin(map->angley) - z;
}

void	zoom(t_vect3 *v, t_vect3 *v1, t_fdf *map)
{
	v->z = map->vz[(int)v->y][(int)v->x];
	v1->z = map->vz[(int)v1->y][(int)v1->x];
	v->z *= map->elevat;
	v->x *= map->zoom;
	v->y *= map->zoom;
	v1->z *= map->elevat;
	v1->x *= map->zoom;
	v1->y *= map->zoom;
}

void	shifting(t_vect3 *v, t_vect3 *v1, t_fdf *map)
{
	v->x += map->shiftx;
	v->y += map->shifty;
	v1->x += map->shiftx;
	v1->y += map->shifty;
}
