/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_float.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 14:13:18 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 13:56:10 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			last_number(t_param *param, double f, unsigned long in)
{
	while (param->prec > 1)
	{
		ret_putchar(param, '0');
		param->prec--;
	}
	f -= in;
	f *= 10;
	in = (unsigned long)f;
	in = round_up(param, f, in);
	ret_putnbr(param, in);
}

static void			print_float(t_param *param, double f, unsigned long in)
{
	if (param->prec == 0)
	{
		f -= in;
		f *= 10;
		if (f > 5)
			in++;
		ret_putnbr(param, in);
	}
	if (param->prec > 0 || param->hflag == 1)
		ret_putchar(param, '.');
	if (param->prec == 0)
		return ;
	while (f > 0 && param->prec > 1)
	{
		f -= in;
		f *= 10;
		in = (unsigned long)f;
		if (check_next(param, f, in))
			return ;
		ret_putnbr(param, in);
		param->prec--;
	}
	last_number(param, f, in);
}

static void			set_it(t_param *param, double f, unsigned long in, int sign)
{
	int				w;
	int				x;

	x = 0;
	if ((f != f) || (f >= __LDBL_MAX__) || (f <= (__LDBL_MAX__ * -1)))
		x = 2;
	if (param->prec == 0 && x == 0)
		in = round_up(param, f, in);
	w = float_width(param, in, sign, x);
	prec_sign(param, sign, w, x);
	if (param->prec > 0)
	{
		if (check_roundl(param, f, in))
			x = 1;
	}
	if (param->prec > 0 && x == 0)
		ret_putnbr(param, in);
	if (float_behavior(param) && x == 0)
		print_float(param, f, in);
	if (x == 2)
		float_exeptions(param, f);
	if (w > 0 && param->mflag == 1)
		print_width(param, w, ' ');
}

void				set_float(va_list ap, t_param *param)
{
	double			f;
	int				sign;
	unsigned long	in;

	sign = 0;
	if (param->prec == -1)
		param->prec = 6;
	f = va_arg(ap, double);
	if (f == 0)
		sign = float_sign(f);
	if (f < 0)
	{
		sign = 1;
		f *= -1;
	}
	in = (unsigned long)f;
	set_it(param, f, in, sign);
}
