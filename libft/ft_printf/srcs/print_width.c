/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 17:43:26 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		print_width(t_param *param, int w, char c)
{
	while (w > 0)
	{
		ret_putchar(param, c);
		w--;
	}
}
