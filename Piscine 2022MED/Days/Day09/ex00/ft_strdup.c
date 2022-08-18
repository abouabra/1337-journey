/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:34:01 by abouabra          #+#    #+#             */
/*   Updated: 2022/05/24 21:29:16 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*mal;
	int		i;

	len = ft_strlen(src);
	mal = (char *)malloc(len * 1);
	if (!mal)
		return (0);
	i = 0;
	while (src[i])
	{
		mal[i] = src[i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}
