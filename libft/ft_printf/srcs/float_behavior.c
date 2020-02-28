/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_behavior.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 15:33:16 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		float_behavior(t_param *param)
{
	if (param->h != 0 || param->hh != 0)
	{
		ret_putchar(param, '\0');
		return (0);
	}
	return (1);
}
