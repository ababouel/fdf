/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:42:20 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/20 15:42:24 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (index < n)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}

int	ft_strchrbis(char *s)
{
	int	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index])
	{
		if (s[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*data;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == 0 || s2 == 0)
		return (0);
	data = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (data)
	{
		ft_memcpy(data, s1, ft_strlen(s1));
		ft_memcpy(data + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	}
	free(s1);
	return (data);
}
