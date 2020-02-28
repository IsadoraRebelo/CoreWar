/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_params.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 16:47:28 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/21 11:39:42 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	line_check(char *line)
{
	int i;

	i = 0;
	while (ft_whitespace(line[i]))
		i++;
	while (ft_isalpha(line[i]))
		i++;
	while (ft_whitespace(line[i]))
		i++;
	return (i);
}

void		get_params(char *line, t_ins *ins)
{
	int	j;
	int	len;
	int	i;

	j = 0;
	len = ft_strlen(line);
	ins->params = ft_strnew(len + 1);
	i = line_check(line);
	while (i < len && line[i] != 0)
	{
		ins->params[j] = line[i];
		j++;
		i++;
	}
	ins->params[j] = 0;
	j--;
	while (ft_whitespace(ins->params[j]))
	{
		ins->params[j] = 0;
		j--;
	}
}
