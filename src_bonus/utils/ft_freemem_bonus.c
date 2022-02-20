/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemem_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:39:03 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/20 15:39:13 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

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
