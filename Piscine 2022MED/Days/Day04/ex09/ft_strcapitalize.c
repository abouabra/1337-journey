/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:28:28 by abouabra          #+#    #+#             */
/*   Updated: 2022/05/21 12:46:05 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i - 1;
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		if ((str[j] < 48 || (str[j] >= 58 && str[j] <= 64)
				|| (str[j] >= 91 && str[j] <= 96) || str[j] > 122)
			&& (str[i] < 123 && str[i] > 96))
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
