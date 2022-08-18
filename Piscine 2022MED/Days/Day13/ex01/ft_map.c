/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 02:18:50 by abouabra          #+#    #+#             */
/*   Updated: 2022/06/02 12:37:51 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*str;

	i = 0;
	str = (int *)malloc(length * sizeof(int));
	if (!str)
		return (0);
	while (i < length)
	{
		str[i] = f(tab[i]);
		i++;
	}
	return (str);
}
