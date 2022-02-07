/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:53:26 by ababouel          #+#    #+#             */
/*   Updated: 2022/01/21 17:58:25 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	getnbrline(char *namefile)
{
	char	*line;
	int		nbrline;
	int		fd;

	nbrline = 0;
	fd = open(namefile, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		nbrline++;
		free(line);
	}
	close(fd);
	return (nbrline);
}

int	getnbrword(char *namefile)
{
	char	*line;
	int		nbrword;
	char	**data;
	int		fd;
	int		size;

	nbrword = 0;
	size = 0;
	fd = open(namefile, O_RDONLY, 0);
	get_next_line(fd, &line);
	data = ft_split(line, ' ');
	while (data[nbrword])
		nbrword++;
	free(line);
	free(data);
	close(fd);
	return (nbrword);
}

void	addz(t_fdf *fdx, char *line, int index)
{
	char	**data;
	int		indey;

	indey = 0;
	data = ft_split(line, ' ');
	while (indey < fdx->larg)
	{
		fdx->vz[index][indey] = (int) atoi(data[indey]);
		indey++;
	}
	free(data);
}

void	parsemap(t_fdf *data, char *nfile)
{
	int		fd;
	char	*line;
	int		index;

	data->haut = getnbrline(nfile);
	data->larg = getnbrword(nfile);
	fd = open(nfile, O_RDONLY, 0);
	index = 0;
	data->vz = malloc(sizeof(int *) * data->haut);
	while (index < data->haut)
	{
		data->vz[index] = malloc(sizeof(int) * data->larg);
		if (!data->vz[index])
			data->vz = ft_freemem(data->vz, index);
		index++;
	}
	index = 0;
	while ((get_next_line(fd, &line)) != 0)
	{
		addz(data, line, index);
		free(line);
		index++;
	}
	close(fd);
}
