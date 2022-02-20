/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:40:30 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/20 15:40:36 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

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
