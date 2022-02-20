/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:51:36 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/16 18:52:14 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ispace(const char *str, int index)
{
	while (str[index] == ' '
		|| str[index] == '\n'
		|| str[index] == '\t'
		|| str[index] == '\v'
		|| str[index] == '\r'
		|| str[index] == '\f')
		index++;
	return (index);
}

int	ft_atoi(const char *str)
{
	int	index;
	int	nbr;
	int	k;

	index = 0;
	nbr = 0;
	k = 1;
	index = ispace(str, index);
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			k = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		nbr = nbr * 10 + (str[index] - '0');
		index++;
	}
	return (k * nbr);
}
