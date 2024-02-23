/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:06:53 by abouabra          #+#    #+#             */
/*   Updated: 2022/05/12 17:20:26 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = size -1;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		j--;
		i++;
	}
}
