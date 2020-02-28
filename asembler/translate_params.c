/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_params.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 13:08:54 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/24 13:36:44 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	set_regestry(t_asm *tasm, char *param)
{
	ft_putchar_fd(ft_atoi(&param[1]), tasm->fd);
	tasm->cursor++;
	tasm->arg_cursor++;
}

int			set_labels(t_asm *tasm, char *param)
{
	t_label	*temp;
	int		i;
	long	nb;

	nb = 0;
	i = 0;
	temp = tasm->labels;
	while (temp)
	{
		if (ft_strequ(param, temp->labels))
		{
			nb = (temp->first_byte + tasm->arg_cursor) - tasm->cursor;
			return (nb);
		}
		temp = temp->next;
	}
	return (0);
}

static void	set_indirect(t_asm *tasm, char *param)
{
	long long	nb;
	char		**tmp;

	tmp = ft_strsplit(param, ',');
	param = *tmp;
	if (param[0] == ':')
		nb = set_labels(tasm, param + 1) % BY2;
	else
		nb = ft_atoi(param) % BY2;
	if (nb < 0)
		nb += BY2;
	ft_putchar_fd(nb / 256, tasm->fd);
	ft_putchar_fd(nb % 256, tasm->fd);
	tasm->cursor += 2;
	tasm->arg_cursor += 2;
	free_double_arr(tmp);
}

static void	navigate_params(t_asm *tasm, char *param, t_ins *tmp)
{
	if (param[0] == 'r')
		set_regestry(tasm, param);
	else if (param[0] == '%')
		set_direct(tasm, param, tmp);
	else
		set_indirect(tasm, param);
}

void		translate_params(t_asm *tasm, t_ins *tmp, int j)
{
	char	*param;
	char	*temp;
	int		nb_params;

	temp = 0;
	param = ft_strdup(tmp->params);
	nb_params = set_max(tmp->id);
	while (j < nb_params)
	{
		temp = param;
		param = ft_strtrim(param);
		free(temp);
		navigate_params(tasm, param, tmp);
		temp = param;
		temp = ft_strchr(param, SEPARATOR_CHAR) ?
			ft_strchr(param, SEPARATOR_CHAR) + 1 : param;
		if (temp != param)
		{
			temp = ft_strdup(temp);
			free(param);
			param = temp;
		}
		j++;
	}
	free(param);
}
