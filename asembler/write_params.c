/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_params.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 11:54:51 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/24 13:43:49 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	cal_bytes(char *param, unsigned char binary, int j)
{
	if (param[0] == 'r')
		binary = binary + (REG_CODE << ((3 - j) * 2));
	else if (param[0] == '%')
		binary = binary + (DIR_CODE << ((3 - j) * 2));
	else
		binary = binary + (IND_CODE << ((3 - j) * 2));
	return (binary);
}

static char	*set_temp(char *temp, char *param)
{
	temp = param;
	temp = ft_strchr(param, SEPARATOR_CHAR) ?
		ft_strchr(param, SEPARATOR_CHAR) + 1 : param;
	return (temp);
}

static void	encoding_byte(t_asm *tasm, t_ins *tmp, unsigned char binary, int j)
{
	char			*param;
	char			*temp;
	int				nb_params;

	nb_params = set_max(tmp->id);
	param = ft_strdup(tmp->params);
	while (j < nb_params)
	{
		temp = param;
		param = ft_strtrim(param);
		free(temp);
		binary = cal_bytes(param, binary, j);
		temp = set_temp(temp, param);
		if (temp != param)
		{
			temp = ft_strdup(temp);
			free(param);
			param = temp;
		}
		j++;
	}
	free(param);
	ft_putchar_fd(binary, tasm->fd);
	tasm->cursor++;
	tasm->arg_cursor++;
}

void		write_params(t_asm *tasm)
{
	t_ins	*tmp;

	tmp = tasm->instruction;
	while (tmp)
	{
		tasm->arg_cursor = 0;
		ft_putchar_fd(tmp->id, tasm->fd);
		tasm->cursor++;
		tasm->arg_cursor++;
		if (tmp->id != 1 && tmp->id != 9
			&& tmp->id != 12 && tmp->id != 15)
			encoding_byte(tasm, tmp, 0, 0);
		translate_params(tasm, tmp, 0);
		tmp = tmp->next;
	}
}
