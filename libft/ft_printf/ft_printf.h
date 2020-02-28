/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 17:18:28 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/27 10:49:13 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../includes/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct		s_param
{
	int				hflag;
	int				pflag;
	int				mflag;
	char			c;
	int				sflag;
	int				width;
	int				l;
	int				lo;
	int				ll;
	int				h;
	int				hh;
	int				prec;
	int				ret;
}					t_param;

typedef union		u_floatunion
{
	long double		flnb;
	short			shnb[5];
}					t_floatunion;

int					ft_printf(char *fmt, ...);
void				ret_putchar(t_param *param, char c);
void				ret_putstr(t_param *param, char *s);
void				ret_putnbr(t_param *param, long long n);
void				ret_putnbr_u(t_param *param, unsigned long long n);
int					str_part(char *str, int i, va_list ap, t_param *param);
int					set_prec(char *str, int i, t_param *param);
void				set_character(va_list ap, t_param *param);
void				set_number(va_list ap, t_param *param);
void				set_unumber(va_list ap, t_param *param);
void				set_octal(va_list ap, t_param *param);
void				set_string(va_list ap, t_param *param);
void				set_float(va_list ap, t_param *param);
void				set_floatl(va_list ap, t_param *param);
void				set_hex(va_list ap, t_param *param);
void				set_hex_up(va_list ap, t_param *param);
void				set_pointer(va_list ap, t_param *param);
void				set_percent(t_param *param);
void				flags(char c, t_param *param);
int					width(char *str, int i, t_param *param);
void				print_width(t_param *param, int w, char c);
int					check_next(t_param *param, double f, unsigned long in);
int					check_nextl(t_param *param, long double f,
								unsigned long long in);
int					check_round(t_param *param, double f,
								unsigned long in);
int					check_roundl(t_param *param, long double f,
								unsigned long long in);
unsigned long long	round_up(t_param *param, double f, unsigned long long in);
int					float_width(t_param *param, unsigned long in, int sign,
								int x);
int					float_behavior(t_param *param);
void				float_exeptions(t_param *param, long double f);
int					float_sign(long double f);
void				prec_sign(t_param *param, int sign, int w, int x);

#endif
