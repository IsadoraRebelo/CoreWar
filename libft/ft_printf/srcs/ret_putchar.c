/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ret_putchar.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 17:29:59 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ret_putchar(t_param *param, char c)
{
	param->ret++;
	write(1, &c, 1);
}
