/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:14:57 by abouabra          #+#    #+#             */
/*   Updated: 2022/05/24 13:15:00 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_baselen(char *base)
{
	int	i;
	int	j;

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
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
			return (0);
		++i;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	base_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{	
	int	integer;
	int	sign;
	int	i;

	integer = 0;
	sign = 1;
	i = 0;
	if (!ft_baselen(base))
		return (0);
	while (str[i] <= 32 && str[i])
		++i;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	while (str[i] && base_index(base, str[i]) != -1)
	{
		integer = (integer * ft_baselen(base)) + base_index(base, str[i]);
		++i;
	}
	return (integer * sign);
}
