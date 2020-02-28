/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_arguments_number.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 13:59:44 by lsmienk        #+#    #+#                */
/*   Updated: 2020/02/24 13:59:48 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int	get_arguments_number(int opcode)
{
	if (opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15 ||
	opcode == 16)
		return (1);
	else if (opcode == 2 || opcode == 3 || opcode == 13)
		return (2);
	else if (opcode == 4 || opcode == 5 || opcode == 6 || opcode == 7 ||
	opcode == 8 || opcode == 10 || opcode == 11 || opcode == 14)
		return (3);
	else
		return (0);
}
