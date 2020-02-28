/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_exceptions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 11:14:22 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			float_exeptions(t_param *param, long double f)
{
	if (f != f)
		ret_putstr(param, "nan");
	if (f > __LDBL_MAX__)
		ret_putstr(param, "inf");
	if (f < (__LDBL_MAX__ * -1))
		ret_putstr(param, "inf");
}
