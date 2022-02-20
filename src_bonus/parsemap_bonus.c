/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:34:43 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/20 16:00:14 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf_bonus.h"

int	ft_atohx(char *hex)
{
	int	length;
	int	base;
	int	decimal;

	length = ft_strlen(hex) - 1;
	base = 1;
	decimal = 0;
	while (length >= 0)
	{
		if (hex[length] >= '0' && hex[length] <= '9')
			decimal += (hex[length] - 48) * base;
		if (hex[length] >= 'A' && hex[length] <= 'F')
			decimal += (hex[length] - 55) * base;
		if (hex[length] >= 'a' && hex[length] <= 'f')
			decimal += (hex[length] - 87) * base;
		base *= 16;
		length--;
	}
	return (decimal);
}

void	injectdata(int *vz, char *gline, t_fdf *map, int *color)
{
	char	**dataz;
	int		i;
	char	*dataco;

	i = 0;
	dataz = ft_split(gline, ' ');
	while (i < map->larg)
	{	
		vz[i] = ft_atoi(dataz[i]);
		dataco = ft_strchr(dataz[i], ',');
		if (dataco == 0)
		{
			if (vz[i] != 0)
				color[i] = 0x00ff00;
			else
				color[i] = 0xffffff;
		}
		else
			color[i] = ft_atohx(dataco);
		i++;
	}
	ft_freememx((void **)dataz, map->larg);
}

int	parsemap(t_fdf *map, char *nfile)
{
	int		fd;
	char	*line;
	int		index;

	index = 0;
	map->haut = getnbrline(nfile, map);
	if (map->haut == -1)
		return (-1);
	map->vz = malloc(sizeof(int *) * (map->haut + 1));
	map->color = malloc(sizeof(int *) * (map->haut));
	fd = open(nfile, O_RDONLY, 0);
	while (index < map->haut)
	{
		map->vz[index] = malloc(sizeof(int) * (map->larg));
		map->color[index] = malloc(sizeof(int) * (map->larg));
		line = get_next_line(fd);
		injectdata(map->vz[index], line, map, map->color[index]);
		free(line);
		index++;
	}
	map->vz[index] = NULL;
	close(fd);
	return (0);
}
