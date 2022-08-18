/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:43:34 by abouabra          #+#    #+#             */
/*   Updated: 2022/05/31 15:25:44 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkbase(char *base)
{
	int	bindex;
	int	index;
	int	tindex;

	bindex = 0;
	index = 0;
	while (base[bindex])
		bindex++;
	if (bindex < 2)
		return (0);
	while (base[index])
	{
		if (base[0] == '\0' || base[index] == '-' || base[index] == '+'
			|| base[index] == ' ' || (base[index] >= 9 && base[index] <= 13))
			return (0);
		tindex = index + 1;
		while (tindex < bindex)
		{
			if (base[index] == base[tindex])
				return (0);
			tindex++;
		}
		index++;
	}
	return (1);
}

int	find_index(char j, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == j)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_atoi_base(char *str, char *base)
{
	int	index;
	int	total;
	int	minus;

	index = 0;
	total = 0;
	minus = 1;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			minus *= -1;
		index++;
	}
	while (str[index])
	{
		if (find_index(str[index], base) == -1 || !checkbase(base))
			return (total * minus);
		total *= ft_strlen(base);
		total += find_index(str[index], base);
		index++;
	}
	return (total * minus);
}
