/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ret_putstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 17:31:32 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ret_putstr(t_param *param, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ret_putchar(param, s[i]);
		i++;
	}
}
