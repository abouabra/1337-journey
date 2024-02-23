/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jj.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:11:01 by abouabra          #+#    #+#             */
/*   Updated: 2022/05/22 19:41:29 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			write(1, &av[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

void	ft_switch(int i, int j, char **av)
{
	char	*a;
	int		z;

	z = 0;
	while (av[i][z] == av[j][z])
		z++;
	if (av[i][z] > av[j][z])
	{
		a = av[i];
		av[i] = av[j];
		av[j] = a;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	z;

	i = 1;
	z = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			ft_switch(i, j, av);
			j++;
		}
		i++;
	}
	print(ac, av);
	return (0);
}
