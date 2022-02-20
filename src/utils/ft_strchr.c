/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:34:25 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/14 17:52:02 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;
	int	x;

	x = 0;
	index = 0;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			return ((char *)&s[++index]);
		index++;
	}
	return (0);
}
