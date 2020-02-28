/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_params.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 11:53:19 by lsmienk        #+#    #+#                */
/*   Updated: 2020/02/21 15:26:56 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			set_max(int id)
{
	int max;

	max = 0;
	if (id == 1 || id == 9 || id == 12 || id == 15 || id == 16)
		max = 1;
	else if (id == 2 || id == 3 || id == 13)
		max = 2;
	else
		max = 3;
	return (max);
}

static int	count_arguments(t_ins *tmp)
{
	int i;
	int max;
	int amount;

	i = 0;
	max = set_max(tmp->id);
	amount = 1;
	while (tmp->params[i] != '\0')
	{
		if (tmp->params[i] == SEPARATOR_CHAR)
			amount++;
		if (tmp->params[i] == COMMENT_CHAR)
			break ;
		i++;
	}
	if (amount != max)
		error_message(14, tmp->params);
	return (max);
}

static void	check_arguemnt_type(t_asm *tasm, char *line, int id, int max)
{
	int i;

	i = 0;
	while (ft_whitespace(line[i]))
		i++;
	i = check_first_arg(tasm, line, i, id) + 1;
	if (max == 1)
		return ;
	while (ft_whitespace(line[i]))
		i++;
	i = check_second_arg(tasm, line, i, id) + 1;
	if (max == 2)
		return ;
	while (ft_whitespace(line[i]))
		i++;
	check_third_arg(tasm, line, i, id);
}

void		check_params(t_asm *tasm)
{
	t_ins	*tmp;
	int		max;

	tmp = tasm->instruction;
	while (tmp)
	{
		max = count_arguments(tmp);
		check_arguemnt_type(tasm, tmp->params, tmp->id, max);
		tmp = tmp->next;
	}
}
