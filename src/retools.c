/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:58:56 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/19 18:50:23 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	clearimage(t_image *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->htigs)
	{
		x = 0;
		while (x < img->whigs)
		{
			img->dst = img->buffer +(y * img->lbytes + x * (img->pbits / 8));
			*(unsigned int *)img->dst = 0x000000;
			x++;
		}
		y++;
	}
}

void	reimg(t_fdf *map)
{
	clearimage(map->igs);
	ft_imagemodif(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 250, 0);
}

int	getnbrline(char *namefile, t_fdf *map)
{
	char	*lns;
	int		nbrline;
	int		fd;

	nbrline = 0;
	fd = open(namefile, O_RDONLY, 0);
	if (fd == -1)
		return (-1);
	lns = get_next_line(fd);
	if (lns == 0)
		return (-1);
	map->larg = getnbrword(lns);
	while (lns != 0)
	{
		nbrline++;
		free(lns);
		lns = get_next_line(fd);
	}
	free(lns);
	close(fd);
	return (nbrline);
}

int	getnbrword(char *lns)
{
	int		nbrword;
	char	**data;

	nbrword = 0;
	data = ft_split(lns, ' ');
	while (data[nbrword])
		nbrword++;
	ft_freememx((void **)data, nbrword);
	return (nbrword);
}
