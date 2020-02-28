/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:38:03 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/21 15:15:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		read_list(t_asm *tasm, t_header *header)
{
	char		*line;
	t_list		*temp;

	temp = tasm->file;
	line = tasm->file->content;
	while (ft_whitespace(line[0]) || line[0] == '#' || line[0] == '\0')
	{
		temp = temp->next;
		line = temp->content;
	}
	check_name(line, header);
	temp = temp->next;
	line = temp->content;
	check_comment(line, header);
	while (temp)
	{
		temp = temp->next;
		if (!temp)
			break ;
		line = temp->content;
		if (line[0] != '\0')
			set_instructions(line, tasm);
	}
	check_params(tasm);
}
