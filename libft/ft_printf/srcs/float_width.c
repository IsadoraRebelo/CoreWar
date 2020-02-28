/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 15:24:14 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 12:40:45 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				float_width(t_param *param, unsigned long in, int sign, int x)
{
	int w;

	if (x == 0)
		w = param->width - ft_intlen(in) - param->prec - sign;
	if (x == 2)
	{
		w = param->width - 3;
		if (sign == 0)
			w++;
	}
	if (param->pflag == 1 && sign == 0)
		w--;
	if (param->prec != 0)
		w--;
	if (param->mflag == 1 && param->sflag == 1 && sign == 0)
		w--;
	if (param->prec == 0 && param->c == '0')
		return (w);
	if (w > 0 && param->mflag == 0)
		print_width(param, w, param->c);
	return (w);
}
