/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:03:11 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/17 11:02:33 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_original(char *s, t_vars *vars)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_original(s[i], vars);
		i++;
	}
}

void	handle_string_precision(t_vars *vars, int flag_counter, char *str)
{
	int	i;

	i = 0;
	vars->flags[width] = 0;
	while (str[i] && i < flag_counter)
	{
		ft_putchar_original(str[i], vars);
		i++;
	}
	vars->int_len[width] = 0;
	vars->flag_counter[width] = 0;
}

void	put_str_flag_minus(t_vars *vars, char *s, int len_of_str)
{
	if (vars->flags[minus] == 1)
	{
		if (vars->flags[precision] == 1)
		{
			if (vars->flag_counter[precision] > len_of_str)
				vars->flag_counter[precision] = len_of_str;
			handle_string_precision(vars, vars->flag_counter[precision], s);
			handle_padding(vars, vars->flag_counter[minus],
				vars->flag_counter[precision], ' ');
			set_the_end(vars, precision);
			set_the_end(vars, minus);
			return ;
		}
		ft_putstr_original(s, vars);
		handle_padding(vars, vars->flag_counter[minus], len_of_str, ' ');
		set_the_end(vars, minus);
	}
}

void	ft_putstr(char *s, t_vars *vars)
{
	int	len_of_str;

	if (!s)
		s = "(null)";
	len_of_str = ft_strlen(s);
	if (vars->flags[width] == 1 && vars->flags[precision] != 1)
		handle_width(vars, len_of_str);
	if (vars->state == 0)
	{
		ft_putstr_original(s, vars);
		return ;
	}
	put_str_flag_minus(vars, s, len_of_str);
	if (vars->flags[precision] == 1)
	{
		if (vars->flag_counter[precision] < len_of_str)
			len_of_str = vars->flag_counter[precision];
		handle_width(vars, len_of_str);
		handle_string_precision(vars, vars->flag_counter[precision], s);
		set_the_end(vars, precision);
	}
}
