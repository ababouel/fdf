/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:33:27 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/20 15:33:43 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf_bonus.h"

void	setotherinit(t_fdf *map)
{
	if (map->larg < 50 && map->haut < 50)
	{
		map->zoom = 30;
		map->elevat = 2;
	}
	else if (map->larg < 100 && map->haut < 100)
	{
		map->zoom = 15;
		map->elevat = 2;
	}
	else
	{
		map->zoom = 2;
		map->elevat = 1;
	}
}

void	setinit(t_fdf *map)
{
	map->htscrn = 1080;
	map->whscrn = 1920;
	map->igs->htigs = map->htscrn;
	map->igs->whigs = 1920 - 250;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->whscrn, map->htscrn, "FDF");
	menudraw(map);
	map->img = mlx_new_image(map->mlx, map->whscrn, map->htscrn);
	setotherinit(map);
	map->isomet = 1;
	map->anglex = 0.523599;
	map->angley = 0.523599;
	map->shiftx = (1080 - 30) / 2;
	map->shifty = map->htscrn / 2 - (map->larg * map->zoom) / 3;
	map->igs->buffer = mlx_get_data_addr(map->img,
			&map->igs->pbits,
			&map->igs->lbytes,
			&map->igs->endian);
}

int	main(int ac, char **av)
{
	t_fdf	*map;
	int		index;
	int		rem;

	if (ac == 2)
	{
		rem = 0;
		index = 0;
		map = malloc(sizeof(t_fdf));
		map->igs = malloc(sizeof(t_image));
		rem = parsemap(map, av[1]);
		if (rem == -1)
			return (1);
		setinit(map);
		menudraw(map);
		ft_imagemodif(map);
		mlx_put_image_to_window(map->mlx, map->win, map->img, 250, 0);
		mlx_key_hook(map->win, key_release, map);
		mlx_hook(map->win, 17, 1L << 0, closes, map);
		mlx_loop(map->mlx);
	}
	return (0);
}
