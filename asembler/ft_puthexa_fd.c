/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthexa_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 13:26:16 by lsmienk        #+#    #+#                */
/*   Updated: 2020/02/24 13:26:34 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_puthexa_fd(long code, int fd)
{
	if (code >= 256)
	{
		ft_puthexa_fd(code / 256, fd);
		ft_puthexa_fd(code % 256, fd);
	}
	else
		ft_putchar_fd(code, fd);
}
