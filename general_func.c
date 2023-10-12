/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:47:29 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/17 17:47:33 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	general_single_flag(t_vars *vars, int len_of_int, long long n,
		int index)
{
	if (index == zero || index == precision)
	{
		if (vars->flag_counter[index] < len_of_int)
			vars->flag_counter[index] = len_of_int;
		handle_padding(vars, vars->flag_counter[index], len_of_int, '0');
	}
	if (index != precision || (index == precision && n != 0))
		ft_putnbr_base_original(n, vars->base, vars);
	if (index == minus)
		handle_padding(vars, vars->flag_counter[index], len_of_int, ' ');
	set_the_end(vars, index);
}

void	general_multiple_flag(t_vars *vars, int len_of_int, long long n,
		int index)
{
	if (n < 0)
		vars->flag_counter[index]--;
	if (vars->flag_counter[precision] < len_of_int)
		vars->flag_counter[precision] = len_of_int;
	if (index == minus)
		handle_padding(vars, vars->flag_counter[precision], len_of_int, '0');
	else if (index == zero)
		handle_padding(vars, vars->flag_counter[zero],
			vars->flag_counter[precision], ' ');
	if (index == zero && n < 0)
	{
		ft_putchar_original('-', vars);
		vars->flag_counter[precision]--;
		len_of_int--;
	}
	if (index == zero)
		handle_padding(vars, vars->flag_counter[precision], len_of_int, '0');
	if (n != 0)
		ft_putnbr_base_original(n, vars->base, vars);
	if (index == minus)
		handle_padding(vars, vars->flag_counter[minus],
			vars->flag_counter[precision], ' ');
	set_the_end(vars, precision);
	set_the_end(vars, index);
}

void	general_single_flag_b2(t_vars *vars, int len_of_int, long long n,
		int index)
{
	vars->flags[index] = 0;
	if (n >= 0)
		len_of_int++;
	if (vars->flags[hashtag] == 1 && n != 0)
		len_of_int += 2;
	handle_width(vars, len_of_int);
	if (n < 0)
		ft_putchar_original('-', vars);
	if (n >= 0)
	{
		if (index == plus)
			ft_putchar_original('+', vars);
		else if (index == space)
			ft_putchar_original(' ', vars);
		else if (index == hashtag)
		{
			if (!ft_strncmp(vars->base, BASE_X_MIN, 16) && n != 0)
				ft_putstr_original("0x", vars);
			else if (!ft_strncmp(vars->base, BASE_X_MAX, 16) && n != 0)
				ft_putstr_original("0X", vars);
		}
	}
	ft_putnbr_base_original(n, vars->base, vars);
	set_the_end(vars, index);
}

void	print_flags(t_vars *vars, int len_of_int, long long n)
{
	if (vars->flags[zero] == 1)
	{
		if (vars->flags[precision] == 1)
			general_multiple_flag(vars, len_of_int, n, zero);
		else
			general_single_flag(vars, len_of_int, n, zero);
	}
	if (vars->flags[minus] == 1)
	{
		if (vars->flags[precision] == 1)
			general_multiple_flag(vars, len_of_int, n, minus);
		else
			general_single_flag(vars, len_of_int, n, minus);
	}
	if (vars->flags[precision] == 1)
		general_single_flag(vars, len_of_int, n, precision);
	if (vars->flags[plus] == 1)
		general_single_flag_b2(vars, len_of_int, n, plus);
	if (vars->flags[space] == 1)
		general_single_flag_b2(vars, len_of_int, n, space);
	if (vars->flags[hashtag] == 1)
		general_single_flag_b2(vars, len_of_int, n, hashtag);
}

void	general_init_func(long long n, char *base, t_vars *vars)
{
	int	len_of_int;

	vars->base = base;
	len_of_int = digit_len(vars, n, ft_strlen(vars->base));
	if (n == 0 && vars->flags[precision] == 1)
		len_of_int--;
	if (vars->flags[plus] != 1 && vars->flags[space] != 1
		&& vars->flags[hashtag] != 1 && vars->flags[precision] != 1)
		handle_width(vars, len_of_int);
	if (n < 0 && vars->flags[plus] != 1 && vars->flags[space] != 1
		&& (vars->flags[precision] != 1 || vars->flags[zero] != 1))
	{
		ft_putchar_original('-', vars);
	}
	if (vars->state == 0)
	{
		ft_putnbr_base_original(n, vars->base, vars);
		return ;
	}
	print_flags(vars, len_of_int, n);
}
