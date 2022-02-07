/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:20:09 by ababouel          #+#    #+#             */
/*   Updated: 2022/01/16 22:02:56 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*ft_strdup(const char *s)
{
	char	*data;
	int		index;

	data = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!data)
		return (0);
	index = 0;
	while (s[index])
	{
		data[index] = s[index];
		index++;
	}
	data[index] = '\0';
	return (data);
}
