/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:32:31 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/20 15:32:38 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf_bonus.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	if (x < img->whigs & x > 0 & y < img->htigs & y > 0)
	{
		img->dst = img->buffer + (y * img->lbytes + x * (img->pbits / 8));
		*(unsigned int *)img->dst = color;
	}
}

void	ft_linedraw(t_vect3 v, t_vect3 v1, t_fdf *map, t_image *img)
{
	t_pixel	pxl;

	zoom(&v, &v1, map);
	if (map->isomet)
	{
		isometric(&v.x, &v.y, v.z, map);
		isometric(&v1.x, &v1.y, v1.z, map);
	}
	shifting(&v, &v1, map);
	pxl.dltx = v1.x - v.x;
	pxl.dlty = v1.y - v.y;
	pxl.pxls = sqrt((pxl.dltx * pxl.dltx) + (pxl.dlty * pxl.dlty));
	pxl.dltx /= pxl.pxls;
	pxl.dlty /= pxl.pxls;
	pxl.pxlx = v.x;
	pxl.pxly = v.y;
	while (pxl.pxls)
	{
		my_mlx_pixel_put(img, pxl.pxlx, pxl.pxly, v1.color);
		pxl.pxlx += pxl.dltx;
		pxl.pxly += pxl.dlty;
		pxl.pxls--;
	}
}

void	ft_imagemodif(t_fdf *map)
{
	t_vect3	v;
	t_vect3	v1;

	v.y = 0;
	while (v.y < map->haut)
	{
		v.x = 0;
		while (v.x < map->larg)
		{
			if (v.x < map->larg - 1)
			{
				addvect(&v1, v.x + 1, v.y, map->color[(int)v.y][(int)(v.x)]);
				ft_linedraw(v, v1, map, map->igs);
			}
			if (v.y < map->haut - 1)
			{
				addvect(&v1, v.x, v.y + 1, map->color[(int)(v.y)][(int)v.x]);
				ft_linedraw(v, v1, map, map->igs);
			}
			v.x++;
		}
		v.y++;
	}
}
