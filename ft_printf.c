/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:01:40 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/17 10:59:37 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_specifiers(va_list args, t_vars *vars)
{
	if (*(vars->str) == 'c')
		ft_putchar(va_arg(args, int), vars);
	if (*(vars->str) == '%')
		ft_putchar_original('%', vars);
	if (*(vars->str) == 's')
		ft_putstr(va_arg(args, char *), vars);
	if (*(vars->str) == 'd' || *(vars->str) == 'i')
		general_init_func(va_arg(args, int), BASE_D, vars);
	if (*(vars->str) == 'u')
		general_init_func(va_arg(args, unsigned int), BASE_D, vars);
	if (*(vars->str) == 'x')
		general_init_func(va_arg(args, unsigned int), BASE_X_MIN, vars);
	if (*(vars->str) == 'X')
		general_init_func(va_arg(args, unsigned int), BASE_X_MAX, vars);
	if (*(vars->str) == 'p')
		ft_put_adress(va_arg(args, void *), vars);
}

void	scan_str(va_list args, t_vars *vars)
{
	int	i;

	while (*(vars->str))
	{
		if (*(vars->str) == '%')
		{
			(vars->str)++;
			while (!ft_strchr("cspdiuxX%", *(vars->str)))
			{
				i = -1;
				while (++i < 7)
					vars->int_len[i] = 0;
				scan_flags(vars);
				vars->str += vars->int_len[width] + vars->int_len[zero]
					+ vars->int_len[precision] + vars->int_len[minus];
			}
			print_specifiers(args, vars);
		}
		else
			ft_putchar_original(*(vars->str), vars);
		(vars->str)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_vars	*vars;
	int		tracker;
	char	*tmp;

	vars = libft_calloc(1, sizeof(t_vars));
	if (!vars)
		return (0);
	va_start(args, str);
	tracker = 0;
	vars->tracker = &tracker;
	vars->str = ft_strdup((char *)str);
	tmp = vars->str;
	scan_str(args, vars);
	va_end(args);
	free(tmp);
	free(vars);
	return (tracker);
}
