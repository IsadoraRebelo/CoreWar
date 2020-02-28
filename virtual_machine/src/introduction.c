/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   introduction.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:00:04 by lsmienk        #+#    #+#                */
/*   Updated: 2020/02/24 14:00:06 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	introduce_player(t_player *player)
{
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", player->id\
		, player->exec_code_size, player->name, player->comment);
}
