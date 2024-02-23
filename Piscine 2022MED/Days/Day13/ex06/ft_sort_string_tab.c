/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:45:29 by abouabra          #+#    #+#             */
/*   Updated: 2022/06/02 17:57:44 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	z;

	i = 1;
	z = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			ft_switch(i, j, tab);
			j++;
		}
		i++;
	}
}
