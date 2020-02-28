/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 17:31:58 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_printf(char *fmt, ...)
{
	va_list ap;
	t_param param;
	int		i;

	i = 0;
	param.ret = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			i = str_part(fmt, i, ap, &param);
		}
		else
		{
			ret_putchar(&param, fmt[i]);
			i++;
		}
	}
	va_end(ap);
	return (param.ret);
}
