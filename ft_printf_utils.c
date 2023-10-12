/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:37:20 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/16 19:47:09 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	digit_len(t_vars *vars, long long n, int baselen)
{
	int	counter;

	(void)vars;
	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		if (vars->flags[precision] != 1)
			counter++;
	}
	while (n > 0)
	{
		counter++;
		n = n / baselen;
	}
	return (counter);
}

void	ft_putnbr_base_original(long long nb, char *base, t_vars *vars)
{
	int	baselen;

	baselen = ft_strlen(base);
	if (nb < 0)
	{
		nb = nb * -1;
	}
	if (nb >= baselen)
	{
		ft_putnbr_base_original(nb / baselen, base, vars);
		ft_putnbr_base_original(nb % baselen, base, vars);
	}
	else
		ft_putchar_original(base[nb % baselen], vars);
}
