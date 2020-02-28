/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ret_putnbr_u.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 11:15:33 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 11:31:30 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void					ret_putnbr_u(t_param *param, unsigned long long n)
{
	if (n == 0 && param->prec == 0)
		return ;
	if (n >= 10)
	{
		ret_putnbr_u(param, n / 10);
		ret_putnbr_u(param, n % 10);
	}
	else
		ret_putchar(param, n + '0');
}
