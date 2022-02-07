/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:54:30 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/04 00:45:32 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include <stdio.h>

int	keypress(int key,t_fdf *map)
{
	printf("number :%d\n",key);
	//if (key == 35)

	if (key == 34)
		map->angle = 0.8;
	if (key == 0)
		map->angle += 0.1;
	if (key == 1)
		map->angle -= 0.1;	
	if (key == 32)
		map->zoom += 10;
	if (key == 2)
		map->zoom -= 10;
	if (key == 123)
		map->shiftx -= 10;
	if (key == 124)
		map->shiftx += 10;
	if (key == 125)
		map->shifty += 10;
	if (key == 126)
		map->shifty -= 10;
	mlx_clear_window(map->mlx, map->win);
	drawingmap(map);
	if (key == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		free(map);
		exit(0);
	}						
	return (0);
}

int main(int ac, char **av)
{
	t_fdf	*data;

	if (ac == 2)
	{

		data = malloc(sizeof(t_fdf));
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, 1280, 720, "FDF");
		data->zoom = 20;
		data->shiftx = 600;
		data ->shifty = 240;
		data->angle = 0.8; 
		//data->img = mlx_new_image(data->mlx, 640, 360);
		parsemap(data, av[1]);
		drawingmap(data);
		//mlx_put_image_to_window(data->mlx , data->win, data->img, 320, 180);
		//draw(1,1,5,1,data);
		//draw(1,1,1,5,data);
		//draw(1,5,5,5,data);
		mlx_key_hook(data->win, keypress, data);
		mlx_loop(data->mlx);
	}
}
