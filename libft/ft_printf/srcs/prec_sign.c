/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prec_sign.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 13:14:40 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 13:55:48 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				prec_sign(t_param *param, int sign, int w, int x)
{
	if (x != 2)
	{
		if ((param->prec > 1 && param->sflag == 1 && sign == 0) ||
			(param->mflag == 1 && param->sflag == 1 && sign == 0))
			ret_putchar(param, ' ');
	}
	if (param->pflag == 1 && sign == 0)
		ret_putchar(param, '+');
	if (sign == 1)
		ret_putchar(param, '-');
	if (param->hflag == 1)
		w--;
	if (x != 2)
	{
		while (w > 0 && param->c == '0' && param->prec == 0)
		{
			ret_putchar(param, '0');
			w--;
		}
	}
}
