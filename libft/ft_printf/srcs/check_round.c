/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_round.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 13:52:25 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void				print_roundup(t_param *param, unsigned long in)
{
	ret_putnbr(param, in);
	if (param->prec > 0)
		ret_putchar(param, '.');
	while (param->prec > 0)
	{
		ret_putchar(param, '0');
		param->prec--;
	}
}

static int				f_to_i(t_param *param, double f, unsigned long in,
								unsigned long save)
{
	f -= in;
	f *= 10;
	in = (unsigned long)f;
	if (in > 5)
	{
		print_roundup(param, save);
		return (1);
	}
	return (0);
}

int						check_round(t_param *param, double f, unsigned long in)
{
	unsigned long		save;
	int					x;

	save = in + 1;
	x = param->prec;
	f -= in;
	f *= 10;
	in = (unsigned long)f;
	if (in < 9)
		return (0);
	if (in == 9)
	{
		while (x > 1)
		{
			f -= in;
			f *= 10;
			in = (unsigned long)f;
			if (in < 9)
				return (0);
			x--;
		}
	}
	return (f_to_i(param, f, in, save));
}
