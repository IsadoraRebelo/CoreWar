/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_if_label.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 11:24:34 by lsmienk        #+#    #+#                */
/*   Updated: 2020/02/21 15:26:36 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*create_string(char *line, int i)
{
	char	*str;
	int		j;

	j = i;
	while (!ft_whitespace(line[j]) && line[j] != SEPARATOR_CHAR &&
		line[j] != ':' && line[j] != '\0')
		j++;
	if (j - i > 0)
		str = (char*)ft_strnew(j - i);
	else
		str = (char*)ft_strnew(1);
	return (str);
}

int				check_if_label(t_asm *tasm, char *line, int i)
{
	t_label *temp;
	char	*str;
	int		j;

	temp = tasm->labels;
	str = create_string(line, i);
	j = 0;
	while (line[i] && !ft_whitespace(line[i]) && line[i] != ',')
	{
		str[j] = line[i];
		j++;
		i++;
	}
	while (temp)
	{
		if (ft_strequ(str, temp->labels))
		{
			free(str);
			return (i);
		}
		temp = temp->next;
	}
	free(str);
	error_message(ERROR_PARAM, line);
	return (i);
}
