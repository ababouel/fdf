/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:41:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/20 15:41:52 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static char	*ft_getread(char *buff, int fd, int bytes)
{
	char	*data;

	data = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!data)
		return (NULL);
	while (!ft_strchrbis(buff) && bytes != 0)
	{
		bytes = read(fd, data, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(data);
			return (0);
		}
		data[bytes] = '\0';
		buff = ft_strjoin(buff, data);
	}
	if (buff[0] == '\0')
	{
		free(data);
		free(buff);
		return (0);
	}
	free(data);
	return (buff);
}

static char	*ft_getline(char *buff, int *len)
{
	char	*data;
	int		index;

	index = 0;
	while (buff[*len] != '\n' && buff[*len])
		*len += 1;
	if (buff[*len] == '\n')
		*len += 1;
	data = malloc(sizeof(char) * (*len + 1));
	if (!data)
		return (0);
	while (buff[index] != '\n' && buff[index])
	{
		data[index] = buff[index];
		index++;
	}
	if (buff[index] == '\n')
	{
		data[index] = buff[index];
		index++;
	}
	data[index] = '\0';
	return (data);
}

static char	*ft_backup(char *str, int len)
{
	char	*data;
	int		index;

	index = 0;
	if (!str)
		return (0);
	data = malloc(sizeof(char) * (ft_strlen(str) - len + 1));
	if (!data)
		return (0);
	while (str[len])
	{
		data[index] = str[len];
		index++;
		len++;
	}
	data[index] = '\0';
	free(str);
	return (data);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*backup;
	int			len;
	int			bytes;

	len = 0;
	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = ft_getread(backup, fd, bytes);
	if (!backup)
		return (0);
	buff = ft_getline(backup, &len);
	backup = ft_backup(backup, len);
	return (buff);
}
