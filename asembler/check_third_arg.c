/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_third_arg.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:25:58 by lsmienk        #+#    #+#                */
/*   Updated: 2020/02/08 12:33:31 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	get_argument_type(t_asm *tasm, char *line, int i)
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
		i = check_if_label(tasm, line, i + 1);
	else
		error_message(ERROR_PARAM, line);
	return (type);
}

void		check_third_arg(t_asm *tasm, char *line, int i, int id)
{
	char		type;

	type = get_argument_type(tasm, line, i);
	if (type == 'i')
		error_message(ERROR_PARAM, line);
	if (type == 'd')
	{
		if (id == 5 || id == 6 || id == 7 || id == 8 || id == 10 || id == 14)
			error_message(ERROR_PARAM, line);
	}
	if (type != 'i')
		i++;
	if (line[i] == ':')
		i = check_if_label(tasm, line, i + 1);
	if (line[i] == '-')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != '\0')
		error_message(ERROR_PARAM, line);
}
