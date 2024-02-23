/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:50:55 by abouabra          #+#    #+#             */
/*   Updated: 2022/05/25 15:02:18 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*tab;
	int	i;

	len = (max - min);
	if (min >= max)
		return (0);
	tab = (int *)malloc(4 * len);
	if (!tab)
		return (0);
	i = 0;
	while (i < len)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
