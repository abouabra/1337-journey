/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:18:14 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/16 19:43:00 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(unsigned long long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		counter++;
		n = n / 16;
	}
	return (counter);
}

void	adress_helper(unsigned long long nb, t_vars *vars)
{
	if (nb >= 16)
	{
		adress_helper(nb / 16, vars);
		adress_helper(nb % 16, vars);
	}
	else
		ft_putchar_original(BASE_X_MIN[nb % 16], vars);
}

void	ft_put_adress(void *ptr, t_vars *vars)
{
	unsigned long long	nb;
	int					len_of_int;

	nb = (unsigned long long)ptr;
	len_of_int = ptr_len(nb) + 2;
	handle_width(vars, len_of_int);
	ft_putstr_original("0x", vars);
	if (vars->state == 0)
	{
		adress_helper(nb, vars);
		return ;
	}
	if (vars->flags[minus] == 1)
	{
		adress_helper(nb, vars);
		handle_padding(vars, vars->flag_counter[minus], len_of_int, ' ');
		set_the_end(vars, minus);
	}
}
