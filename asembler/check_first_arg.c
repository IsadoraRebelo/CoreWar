/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_first_arg.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 13:29:22 by lsmienk        #+#    #+#                */
/*   Updated: 2020/02/21 15:27:19 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		get_argument_type(t_asm *tasm, char *line, int i)
{
	char type;

	type = 'x';
	while (ft_whitespace(line[i]))
		i++;
	if (line[i] == 'r')
		type = 'r';
	else if (line[i] == '%')
		type = 'd';
	else if (ft_isdigit(line[i]) || (line[i] == '-' &&
			ft_isdigit(line[i + 1])))
		type = 'i';
	else if (line[i] == ':')
	{
		i = check_if_label(tasm, line, i + 1);
		type = 'i';
	}
	else
		error_message(ERROR_PARAM, line);
	return (type);
}

static void		check_valid_type(char type, int id, char *line)
{
	if (type == 'i')
	{
		if (id == 1 || id == 3 || id == 4 || id == 5 || id == 9 || id == 11 ||
			id == 12 || id == 15 || id == 16)
			error_message(ERROR_PARAM, line);
	}
	if (type == 'd')
	{
		if (id == 3 || id == 4 || id == 5 || id == 11 || id == 16)
			error_message(ERROR_PARAM, line);
	}
	if (type == 'r')
	{
		if (id == 1 || id == 2 || id == 9 || id == 12 || id == 13 || id == 15)
			error_message(ERROR_PARAM, line);
	}
}

int				check_first_arg(t_asm *tasm, char *line, int i, int id)
{
	char		type;

	type = get_argument_type(tasm, line, i);
	check_valid_type(type, id, line);
	if (type != 'i')
		i++;
	if (line[i] == ':')
	{
		i = check_if_label(tasm, line, i + 1);
		return (i);
	}
	if (line[i] == '-')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != SEPARATOR_CHAR && line[i] != '\0')
		error_message(ERROR_PARAM, line);
	return (i);
}
