/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialise_players.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 13:59:56 by lsmienk        #+#    #+#                */
/*   Updated: 2020/02/24 13:59:59 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static void	get_player_info(t_player *player)
{
	player->name = player->bytecode + 4;
	player->comment = player->bytecode + 4 * 3 + PROG_NAME_LENGTH;
	player->exec_code =\
		player->bytecode + 4 * 4 + PROG_NAME_LENGTH + COMMENT_LENGTH;
	player->exec_code_size =\
		((unsigned char)player->bytecode[PROG_NAME_LENGTH + 8] << 24) |\
		((unsigned char)player->bytecode[PROG_NAME_LENGTH + 9] << 16) |\
		((unsigned char)player->bytecode[PROG_NAME_LENGTH + 10] << 8) |\
		((unsigned char)player->bytecode[PROG_NAME_LENGTH + 11]);
}

int			initialise_players(t_vm *vm)
{
	int		index;
	int		buf_index;
	int		fd;

	index = 0;
	buf_index = 0;
	while (index < vm->n_players)
	{
		fd = open(vm->players[index]->file, O_RDONLY);
		read(fd, vm->players[index]->bytecode,\
			16 + PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE);
		get_player_info(vm->players[index]);
		close(fd);
		if (vm->players[index]->exec_code_size > CHAMP_MAX_SIZE)
			return (0);
		introduce_player(vm->players[index]);
		index++;
	}
	return (1);
}
