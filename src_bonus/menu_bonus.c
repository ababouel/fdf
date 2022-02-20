/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:34:00 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/20 16:01:51 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf_bonus.h"

void	menudraw(t_fdf *map)
{
	mlx_string_put(map->mlx, map->win, 10, 5, 0xffffffff, "place=> (< ^ v >)");
	mlx_string_put(map->mlx, map->win, 10, 30, 0xffffffff, "(depth z)=> w, q");
	mlx_string_put(map->mlx, map->win, 10, 55, 0xffffffff, "zoom=> u, d");
	mlx_string_put(map->mlx, map->win, 10, 80, 0xffffffff, "iso/front=> i, p");
	mlx_string_put(map->mlx, map->win, 10, 105, 0xffffffff, "rotx=> t, y");
	mlx_string_put(map->mlx, map->win, 10, 130, 0xffffffff, "roty=> r, e");
}
