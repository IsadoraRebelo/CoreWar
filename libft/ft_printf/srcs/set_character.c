/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_character.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 11:48:26 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 13:59:17 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	check_behavior(t_param *param)
{
	if (param->l != 0 || param->pflag != 0 || param->lo != 0
		|| param->ll != 0 || param->h != 0 || param->hh != 0)
	{
		ret_putchar(param, '\0');
		return (0);
	}
	return (1);
}

void		set_character(va_list ap, t_param *param)
{
	int w;

	w = param->width - 1;
	if (w > 0 && param->mflag == 0)
		print_width(param, w, param->c);
	if (check_behavior(param))
		ret_putchar(param, va_arg(ap, int));
	if (w > 0 && param->mflag == 1)
		print_width(param, w, param->c);
}
