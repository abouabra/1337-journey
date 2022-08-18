/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:08:36 by hchairi           #+#    #+#             */
/*   Updated: 2022/05/15 19:46:47 by hchairi          ###   ########.fr       */
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
			if ((i == 1 || i == y) && j == 1)
				ft_putchar('A');
			else if (((i == 1 || i == y) && (j > 1 && j < x))
				|| ((i > 1 && i < y) && (j == 1 || j == x)))
				ft_putchar('B');
			else if ((i == 1 || i == y) && j == x)
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
