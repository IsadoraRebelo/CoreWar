/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 15:17:26 by lsmienk        #+#    #+#                */
/*   Updated: 2020/02/24 13:37:59 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		add_line_to_file(t_list *file, char *line)
{
	t_list *temp;
	t_list *new;

	temp = file;
	if (temp->content == NULL)
	{
		temp->content = ft_strdup(line);
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	new = (t_list*)ft_memalloc(sizeof(t_list));
	new->content = ft_strdup(line);
	new->next = NULL;
	temp->next = new;
}

static void		file_reader(int fd, t_asm *tasm)
{
	char	*line;

	tasm->file = (t_list *)ft_memalloc(sizeof(t_list));
	tasm->file->content = NULL;
	tasm->file->next = NULL;
	while (ft_get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\0')
			add_line_to_file(tasm->file, line);
		free(line);
	}
}

static int		call_assembly(char *av)
{
	t_asm		*tasm;
	t_header	*header;

	header = (t_header *)ft_memalloc(sizeof(t_header));
	if (!header)
		exit(1);
	tasm = (t_asm *)ft_memalloc(sizeof(t_asm));
	if (!tasm)
		exit(1);
	ft_bzero(tasm, sizeof(tasm));
	tasm->fd = open(av, O_RDONLY);
	if (tasm->fd == -1)
		error_message(ERROR_FILE, NULL);
	file_reader(tasm->fd, tasm);
	set_op(tasm);
	read_list(tasm, header);
	cor_generator(tasm, av, header);
	free_structs(tasm->labels, header, tasm);
	return (1);
}

int				main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac != 2)
		error_message(ERROR_USAGE, NULL);
	while (i < ac)
	{
		ft_writeincolours("File: ", "light blue");
		ft_printf(av[i]);
		ft_printf("\n");
		ft_writeincolours("Status: ", "light blue");
		if (ft_strlen(av[i]) < 3 || av[i][ft_strlen(av[i]) - 1] != 's' ||
		av[i][ft_strlen(av[i]) - 2] != '.')
			error_message(ERROR_EXTENSION, NULL);
		else
			call_assembly(av[1]);
		i++;
	}
	return (1);
}
