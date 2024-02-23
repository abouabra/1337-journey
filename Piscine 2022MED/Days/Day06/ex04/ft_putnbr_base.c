/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:08:15 by abouabra          #+#    #+#             */
/*   Updated: 2022/05/24 13:08:20 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_baselen(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		++i;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr(int nbr, char *str_base, unsigned int baselen)
{
	unsigned int	num;

	if (nbr < 0)
	{
		ft_putchar('-');
		num = nbr * -1;
	}
	else
		num = nbr;
	if (num >= baselen)
		ft_putnbr((num / baselen), str_base, baselen);
	ft_putchar(str_base[num % baselen]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_baselen(base))
		ft_putnbr(nbr, base, ft_baselen(base));
}
