/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:17:41 by abouabra          #+#    #+#             */
/*   Updated: 2022/06/02 17:17:42 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);
int		ft_atoi(char *str);

int	operator_check(char *s2)
{
	if (s2[0] == '-' || s2[0] == '+' || s2[0] == '*' || s2[0] == '/'
		|| s2[0] == '%')
		return (1);
	return (0);
}

void	div_mod(char op, int num1, int num2)
{
	if (op == '/')
	{
		if (num1 == 0 || num2 == 0)
			write(1, "Stop : division by zero\n", 24);
		else
		{
			ft_putnbr(num1 / num2);
			write(1, "\n", 1);
		}
	}
	if (op == '%')
	{
		if (num1 == 0 || num2 == 0)
			write(1, "Stop : modulo by zero\n", 22);
		else
		{
			ft_putnbr(num1 % num2);
			write(1, "\n", 1);
		}
	}
}

void	add_sub(char op, int num1, int num2)
{
	if (op == '+')
	{
		ft_putnbr(num1 + num2);
		write(1, "\n", 1);
	}
	if (op == '-')
	{
		ft_putnbr(num1 - num2);
		write(1, "\n", 1);
	}
	if (op == '*')
	{
		ft_putnbr(num1 * num2);
		write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	int		num1;
	int		num2;
	char	op;

	if (ac == 4)
	{
		num1 = ft_atoi(av[1]);
		num2 = ft_atoi(av[3]);
		op = av[2][0];
		if (operator_check(av[2]) == 0)
			write(1, "0\n", 2);
		add_sub(op, num1, num2);
		div_mod(op, num1, num2);
	}
	return (0);
}
