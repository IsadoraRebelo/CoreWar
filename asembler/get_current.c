/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_current.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 11:47:16 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/21 11:48:00 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*get_current_label(t_asm *tasm)
{
	t_label	*tmp;
	t_label	*new;

	tmp = tasm->labels;
	new = (t_label *)ft_memalloc(sizeof(t_label));
	if (!tmp)
	{
		tasm->labels = new;
		return (new);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_ins		*get_current_ins(t_asm *tasm)
{
	t_ins	*tmp;
	t_ins	*new;

	tmp = tasm->instruction;
	new = (t_ins *)malloc(sizeof(t_ins));
	ft_bzero(new, sizeof(t_ins));
	if (!tmp)
	{
		tasm->instruction = new;
		return (new);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}
