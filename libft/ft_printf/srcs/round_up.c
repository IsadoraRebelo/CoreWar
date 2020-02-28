/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   round_up.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 16:38:03 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 12:50:52 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long long		round_up(t_param *param, double f,
									unsigned long long in)
{
	unsigned long long	res;
	int					x;

	res = in;
	x = 500;
	f -= in;
	if (f < 0.5)
		return (res);
	if (f > 0.5 || (f == 0.5 && res % 2 != 0))
		return (res + 1);
	if (param->prec == 0 && res % 2 == 0)
		return (res);
	f *= 10;
	in = (unsigned long long)f;
	while (x > 0 && res % 2 == 0)
	{
		if (in > 0)
			return (res + 1);
		f -= in;
		f *= 10;
		in = (unsigned long long)f;
		x--;
	}
	return (res);
}
