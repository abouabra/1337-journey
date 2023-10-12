/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:18:28 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/16 20:11:57 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars
{
	char	*str;
	int		*tracker;
	int		flags[7];
	int		int_len[7];
	int		flag_counter[7];
	int		state;
	char	*base;
}			t_vars;

# define BASE_D "0123456789"
# define BASE_X_MIN "0123456789abcdef"
# define BASE_X_MAX "0123456789ABCDEF"

enum
{
	zero,
	precision,
	minus,
	plus,
	hashtag,
	space,
	width,
};

int			ft_printf(const char *str, ...);

int			ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, int n);
char		*ft_strdup(char *s1);
char		*ft_strchr(const char *s, int c);
void		*ft_memset(void *b, int c, size_t len);
void		*libft_calloc(size_t nitems, size_t size);
int			ft_atoi(char *str);

void		handle_width(t_vars *vars, int int_len);
void		handle_padding(t_vars *vars, int flag_counter, int int_len, char c);
void		scan_flags(t_vars *vars);
void		set_the_end(t_vars *vars, int index);
int			digit_len(t_vars *vars, long long n, int baselen);
void		ft_putnbr_base_original(long long nb, char *base, t_vars *vars);

void		general_single_flag(t_vars *vars, int len_of_int, long long n,
				int index);
void		general_multiple_flag(t_vars *vars, int len_of_int, long long n,
				int index);
void		general_single_flag_b2(t_vars *vars, int len_of_int, long long n,
				int index);
void		print_flags(t_vars *vars, int len_of_int, long long n);
void		general_init_func(long long n, char *base, t_vars *vars);

void		handle_string_precision(t_vars *vars, int flag_counter, char *str);

void		ft_putchar(char c, t_vars *vars);
void		ft_putchar_original(char c, t_vars *vars);

void		ft_putstr(char *s, t_vars *vars);
void		ft_putstr_original(char *s, t_vars *vars);

int			ptr_len(unsigned long long n);
void		ft_put_adress(void *ptr, t_vars *vars);

#endif
