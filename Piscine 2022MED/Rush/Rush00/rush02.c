/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:53:03 by hchairi           #+#    #+#             */
/*   Updated: 2022/05/15 23:07:53 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	j;
	int	i;

	i = 1;
	while (i <= y && x > 0 && y > 0)
	{
		j = 1;
		while (j <= x)
		{
			if ((i == 1 && j == y) || (i == 1 && j == 1))
				ft_putchar('A');
			else if (((i == 1 || i == y) && (j > 1 && j < x))
				|| ((i > 1 && i < y) && (j == 1 || j == x)))
				ft_putchar('B');
			else if ((i == x && j == 1) || (i == x && j == y))
				ft_putchar('C');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	if (x < 0 || y < 0)
		write(1, "Error, Plz choose positive numbers in main();\n", 46);
}
