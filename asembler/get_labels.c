/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_labels.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 12:56:15 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/21 11:02:38 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	compare_labels(char *line, int i)
{
	if (!(ft_strchr(LABEL_CHARS, line[i])))
		error_message(ERROR_INSTRUCTION, line);
	i++;
	return (i);
}

static void	delete_labels(char *line)
{
	int i;

	i = 0;
	while (line[i] != ':')
	{
		line[i] = ' ';
		i++;
	}
	line[i] = ' ';
}

void		get_labels(char *line, t_label *label, t_asm *tasm, int len)
{
	char	*label_line;
	int		i;

	i = 0;
	label_line = ft_strsub(line, 0, len);
	while (i < len && line[i] != LABEL_CHAR)
		i = compare_labels(line, i);
	label->labels = label_line;
	tasm->is_label = 1;
	delete_labels(line);
}
