/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:17:31 by ababouel          #+#    #+#             */
/*   Updated: 2022/01/19 19:02:28 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*ft_data(char c)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * 2);
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);
}

char	*ft_strjoin(char *line, char c)
{
	char	*data;
	int		size;
	int		x;

	size = 0;
	x = 0;
	if (!line)
		data = ft_data(c);
	else
	{
		size = ft_strlen(line);
		data = malloc(sizeof(char) * (size + 2));
		while (x < size)
		{
			data[x] = line[x];
			x++;
		}
		data[x++] = c;
		data[x] = '\0';
		free(line);
	}
	return (data);
}

int	get_next_line(int fd, char **line)
{
	char	buff;
	char	*data;

	data = NULL;
	if (fd == -1)
		return (-1);
	if (data == NULL)
		data = ft_strjoin(data, '\0');
	while (read(fd, &buff, 1) && buff != '\n')
		data = ft_strjoin(data, buff);
	*line = data;
	return (buff == '\n');
}
