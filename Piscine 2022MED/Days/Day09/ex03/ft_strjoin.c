/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:04:07 by abouabra          #+#    #+#             */
/*   Updated: 2022/05/31 15:16:38 by abouabra         ###   ########.fr       */
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

void	ft_link(int size, char **strs, char *sep, char *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			*ptr = strs[i][j];
			j++;
			ptr++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			*ptr = sep[j];
			j++;
			ptr++;
		}
		i++;
	}
	*ptr = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*ptr;
	char	*ptr2;

	len = 0;
	i = 0;
	if (size <= 0)
	{
		ptr = (char *) malloc(sizeof(char *));
		ptr[0] = 0;
		return (ptr);
	}
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	ptr = NULL;
	ptr = malloc(sizeof(char *) * ((len + ft_strlen(sep) * (size - 1)) + 1));
	if (!ptr)
		return (0);
	ptr2 = ptr;
	ft_link(size, strs, sep, ptr);
	return (ptr2);
}
