/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_direct.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 12:27:59 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/24 11:53:27 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_four_bytes(t_asm *tasm, int index, long long nb)
{
	int j;

	j = 0;
	index = 4 - index;
	while (j < index)
	{
		ft_putchar_fd(0, tasm->fd);
		j++;
	}
	if (nb != 0)
		ft_puthexa_fd(nb, tasm->fd);
}

static void	direct_four_bytes(t_asm *tasm, char *param)
{
	long long	nb_temp;
	long long	nb;
	int			index;

	index = 0;
	if (param[1] == ':')
		nb = set_labels(tasm, param + 2) % BY4;
	else
		nb = ft_atoi(param + 1) % BY4;
	if (nb < 0)
		nb += BY4;
	nb_temp = nb;
	index = 0;
	while (nb_temp != 0)
	{
		nb_temp = nb_temp / 256;
		index++;
	}
	write_four_bytes(tasm, index, nb);
	tasm->cursor += 4;
	tasm->arg_cursor += 4;
}

void		set_direct(t_asm *tasm, char *param, t_ins *tmp)
{
	long long	nb;
	long long	nb_temp;
	int			index;
	char		**temp;

	nb_temp = 0;
	index = 0;
	temp = ft_strsplit(param, ',');
	param = *temp;
	if ((tmp->id >= 9 && tmp->id <= 12) || tmp->id == 14 || tmp->id == 15)
	{
		if (param[1] == ':')
			nb = set_labels(tasm, param + 2) % BY2;
		else
			nb = ft_atoi(param + 1) % BY2;
		if (nb < 0)
			nb += BY2;
		ft_putchar_fd(nb / 256, tasm->fd);
		ft_putchar_fd(nb % 256, tasm->fd);
		tasm->cursor += 2;
		tasm->arg_cursor += 2;
	}
	else
		direct_four_bytes(tasm, param);
	free_double_arr(temp);
}
