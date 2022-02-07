/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:08:13 by ababouel          #+#    #+#             */
/*   Updated: 2022/01/16 22:02:03 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static long int	sizenb(int n)
{
	long int	snb;
	long int	xd;

	xd = n;
	snb = 0;
	if (xd < 0)
	{
		xd *= -1;
		snb++;
	}
	while (xd >= 10)
	{
		xd = xd / 10;
		snb++;
	}
	snb++;
	return (snb);
}

static char	*datasize(long int nb)
{
	char	*data;

	data = malloc(sizeof(char) * (nb + 1));
	if (data == NULL)
		return (0);
	data[nb] = '\0';
	return (data);
}

char	*ft_itoa(int n)
{
	long int	nb;
	long int	xd;
	char		*data;

	xd = n;
	nb = sizenb(xd);
	data = datasize(nb);
	if (data == 0)
		return (0);
	while (nb-- > 0)
	{
		if (xd < 0)
			xd *= -1;
		if (xd >= 10)
		{
			data[nb] = (xd % 10 + '0');
			xd = xd / 10;
		}
		else
			data[nb] = (xd % 10 + '0');
	}
	if (n < 0)
		data[0] = '-';
	return (data);
}
