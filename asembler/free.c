/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:30:43 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/21 11:34:18 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_file(t_list *file)
{
	t_list *current;
	t_list *next;

	current = file;
	next = file;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
}

static void	free_ins(t_ins *ins)
{
	t_ins *current;
	t_ins *next;

	current = ins;
	next = ins;
	while (current != NULL)
	{
		next = current->next;
		free(current->params);
		free(current);
		current = next;
	}
}

static void	free_labels(t_label *labels)
{
	t_label *current;
	t_label *next;

	current = labels;
	next = labels;
	while (current != NULL)
	{
		next = current->next;
		free(current->labels);
		free(current);
		current = next;
	}
}

void		free_structs(t_label *label, t_header *header, t_asm *tasm)
{
	free_ins(tasm->instruction);
	tasm->instruction = NULL;
	free_file(tasm->file);
	tasm->file = NULL;
	free(header);
	header = NULL;
	free_labels(label);
	label = NULL;
	free(tasm);
	tasm = NULL;
}
