/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ret_putnbr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 17:40:01 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ret_putnbr(t_param *param, long long n)
{
	if (n == LONG_MIN)
	{
		ret_putchar(param, '-');
		ret_putchar(param, '9');
		n = 223372036854775808;
	}
	if (n < 0)
	{
		ret_putchar(param, '-');
		n *= -1;
	}
	if (n >= 10)
	{
		ret_putnbr(param, (n / 10));
		ret_putnbr(param, (n % 10));
	}
	else
		ret_putchar(param, (n + '0'));
}
