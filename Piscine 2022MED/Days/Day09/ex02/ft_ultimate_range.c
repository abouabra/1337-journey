/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:25:03 by abouabra          #+#    #+#             */
/*   Updated: 2022/05/31 15:15:58 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	*tab;
	int	i;

	if (min >= max)
	{
		tab = NULL;
		return (0);
	}
	len = (max - min);
	tab = (int *)malloc(4 * len);
	if (!tab)
	{
		tab = NULL;
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (len);
}
