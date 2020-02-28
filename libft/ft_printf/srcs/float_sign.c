/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_sign.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 11:40:09 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			float_sign(long double f)
{
	t_floatunion nb;

	nb.flnb = f;
	if ((nb.shnb[4] >> 15) == -1)
		return (1);
	return (0);
}
