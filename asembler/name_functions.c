/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   name_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 15:00:16 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/21 13:19:57 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_name(char *line, t_header *header, int i, int len)
{
	int		j;

	j = 0;
	while (i < len - 1)
	{
		if (line[i] == '.')
			header->prog_name[j] = line[i];
		else
			header->prog_name[j] = line[i];
		j++;
		i++;
	}
	header->prog_name[j] = '\0';
}

void		check_name(char *line, t_header *header)
{
	int	len;
	int i;

	len = ft_strlen(line);
	i = ft_strlen(NAME_CMD_STRING);
	if (ft_strnstr(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == NULL)
		error_message(ERROR_NAME, line);
	while (line[i] && (line[i] == ' ' || line[i] == '\n' || line[i] == '\t'))
		i++;
	if (len - i - (int)ft_strlen(NAME_CMD_STRING - 2 - 1) > PROG_NAME_LENGTH ||
		i == (int)ft_strlen(NAME_CMD_STRING) ||
		line[i] != '"' || line[len - 1] != '"')
		error_message(ERROR_NAME, line);
	i++;
	write_name(line, header, i, len);
}

void		set_filename(t_asm *tasm, t_header *header)
{
	int i;
	int	count;

	count = 0;
	i = 0;
	ft_putchar_fd(0x0, tasm->fd);
	ft_puthexa_fd(COREWAR_EXEC_MAGIC, tasm->fd);
	while (header->prog_name[i])
	{
		ft_putchar_fd(header->prog_name[i], tasm->fd);
		i++;
	}
	while (i < PROG_NAME_LENGTH + 1)
	{
		i++;
		ft_putchar_fd(0x0, tasm->fd);
	}
}
