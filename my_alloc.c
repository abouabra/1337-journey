/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:27:26 by abouabra          #+#    #+#             */
/*   Updated: 2022/10/02 15:06:23 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void custom_exit(int exit_code)
{
	garbage_collector(NULL,1);
	exit(exit_code);
}

void	garbage_collector(void *adress, int arg)
{
	static t_list *head;
	t_list *node;

	
	if(arg)
		ft_lstclear(&head, free);
	else
	{
		node = ft_lstnew(adress);
		ft_lstadd_back(&head, node);
	};
}

void	*my_alloc(size_t size)
{
	void	*str;

	str = malloc(size);
	if (!str)
		return (0);
	ft_memset(str, 0, size);
	garbage_collector(str,0);
	return (str);
}
#include <stdio.h>
#include <fcntl.h>

int main()
{
	void *test;

	test = my_alloc(10);
	test = my_alloc(10);
	test = my_alloc(10);
	test = my_alloc(10);
	test = my_alloc(10);
	test = my_alloc(10);
	test = my_alloc(10);
	test = my_alloc(10);
	test = my_alloc(10);
	ft_split("hello world",' ');
	ft_split("hello world",' ');
	ft_split("hello world",' ');
	ft_split("hello world",' ');
    ft_itoa(123);
    ft_itoa(123);
    ft_itoa(123);
    ft_itoa(123);
    int fd = open("my_alloc.c",O_RDONLY);
    while(1)
    {
        char *tmp = get_next_line(fd);
        if(!tmp)
            break;
    }
	custom_exit(0);
	return 0;
}