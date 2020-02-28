/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_percent.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 16:13:39 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		set_percent(t_param *param)
{
	if (param->width > 0 && param->mflag == 0)
		print_width(param, (param->width - 1), param->c);
	ret_putchar(param, '%');
	if (param->width > 0 && param->mflag == 1)
		print_width(param, (param->width - 1), param->c);
}
