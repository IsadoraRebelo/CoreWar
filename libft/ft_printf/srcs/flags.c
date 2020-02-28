/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/10 18:01:43 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		flags(char c, t_param *param)
{
	if (c == '#')
		param->hflag = 1;
	if (c == '-')
		param->mflag = 1;
	if (c == '+')
		param->pflag = 1;
	if (c == '0')
		param->c = '0';
	if (c == ' ')
		param->sflag = 1;
}
