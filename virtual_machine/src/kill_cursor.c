/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_cursor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 14:30:31 by lsmienk        #+#    #+#                */
/*   Updated: 2020/02/21 14:31:05 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void		kill_cursor(t_cursor *previous, t_cursor **cursor, t_vm *vm)
{
	t_cursor	*tmp;

	tmp = *cursor;
	if (!previous)
	{
		*cursor = (*cursor)->next;
		vm->cursors = *cursor;
	}
	else
	{
		previous->next = (*cursor)->next;
		*cursor = (*cursor)->next;
	}
	free(tmp->arguments);
	tmp->arguments = NULL;
	free(tmp);
	tmp = NULL;
	vm->n_process--;
}
