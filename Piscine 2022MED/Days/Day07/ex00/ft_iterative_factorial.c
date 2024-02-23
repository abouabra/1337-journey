/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:12:20 by abouabra          #+#    #+#             */
/*   Updated: 2022/05/22 20:13:47 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	end;

	if (nb < 0)
		return (0);
	i = 1;
	end = 1;
	while (i <= nb)
	{
		end = end * i;
		i++;
	}
	return (end);
}
