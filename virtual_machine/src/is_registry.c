/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_registry.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 14:02:32 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/25 14:02:55 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int	is_registry(int registry)
{
	if (registry > -1 && registry < 16)
		return (1);
	return (0);
}
