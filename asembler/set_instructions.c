/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_instructions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 15:25:59 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/24 11:22:55 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*delete_comment(char *line, int i)
{
	int len;

	len = 0;
	while (line[i] != '\0')
	{
		line[i] = ' ';
		i++;
	}
	return (line);
}

static char		*first_word(char *line)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	j = 0;
	rtn = (char *)malloc(sizeof(char) * 10);
	while (ft_whitespace(line[i]))
	{
		i++;
	}
	while (ft_isalpha(line[i]))
	{
		rtn[j] = line[i];
		i++;
		j++;
	}
	rtn[j] = 0;
	return (rtn);
}

static int		get_id_by_name(t_asm *tasm, char *name)
{
	int		i;

	i = 0;
	while (i < 17)
	{
		if (!ft_strcmp(name, tasm->op_tab[i].name))
		{
			free(name);
			return (tasm->op_tab[i].id);
		}
		i++;
	}
	error_message(ERROR_INSTRUCTION, name);
	free(name);
	return (0);
}

static void		get_operations(char *tmp, t_asm *tasm, t_ins *current)
{
	int		j;
	int		i;
	int		len;

	j = 0;
	i = 0;
	len = ft_strlen(tmp);
	if (tmp[i] == '\0')
		return ;
	while (i + j < len && !(ft_whitespace(tmp[i + j])))
		j++;
	current->id = get_id_by_name(tasm, first_word(tmp));
	get_params(tmp, current);
	current->is_label = tasm->is_label;
	tasm->index++;
	tasm->is_label = 0;
}

void			set_instructions(char *line, t_asm *tasm)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	j = 0;
	i = 0;
	len = ft_strlen(line);
	while (ft_whitespace(line[i]))
		i++;
	while (i < len)
	{
		if (line[i] == ':' && line[i - 1] != '%' && ft_whitespace(line[i + 1]))
			get_labels(line, get_current_label(tasm), tasm, i);
		else if (line[i] == COMMENT_CHAR)
		{
			line = delete_comment(line, i);
			break ;
		}
		i++;
	}
	tmp = ft_strtrim(line);
	if (!(ft_whitespace(tmp[0])) && tmp[0] != '\0')
		get_operations(tmp, tasm, get_current_ins(tasm));
	free(tmp);
}
