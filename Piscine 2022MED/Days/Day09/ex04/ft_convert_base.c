/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:19:48 by abouabra          #+#    #+#             */
/*   Updated: 2022/06/02 13:23:00 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_index(char j, char *base);
int	ft_atoi_base(char *str, char *base);
int	ft_strlen(char *str);
int	checkbase(char *base);

int	count_nbr(unsigned int index, char *base)
{
	int				b;
	unsigned int	len;

	b = 0;
	len = ft_strlen(base);
	while (index >= len)
	{
		index = index / len;
		b++;
	}
	return (++b);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	nb;
	int				nbneg;
	char			*res;
	int				index;

	if (!checkbase(base_from) || !checkbase(base_to))
		return (0);
	nbneg = ft_atoi_base(nbr, base_from);
	nb = nbneg;
	if (nbneg < 0)
		nb = -nbneg;
	index = count_nbr(nb, base_to) + ((nbneg < 0));
	res = malloc(sizeof(char) * (index + 1));
	res[index] = 0;
	while (index--)
	{
		res[index] = base_to[nb % ft_strlen(base_to)];
		nb = nb / ft_strlen(base_to);
	}
	if (nbneg < 0)
		res[0] = '-';
	return (res);
}
