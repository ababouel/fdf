/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:31:03 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/12 18:01:15 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	**ft_freemem(int	**data, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (data)
			free(data[i]);
		i++;
	}
	free(data);
	return (data);
}

void	ft_freememx(void **data, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (data)
			free(data[i]);
		i++;
	}
	free(data);
}
