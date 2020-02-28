/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cor_generator.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 15:22:32 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/21 13:46:28 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	set_extension(char *str)
{
	int		fd;
	char	*name;
	int		i;

	i = 0;
	name = ft_strnew(ft_strlen(str) + 3);
	while (str[i + 1])
	{
		name[i] = str[i];
		i++;
	}
	name[i] = 'c';
	name[i + 1] = 'o';
	name[i + 2] = 'r';
	name[i + 3] = '\0';
	fd = open(name, O_RDWR | O_CREAT, 0777);
	if (fd == -1)
		return (-1);
	free(name);
	return (fd);
}

static long	exec_count(int j, t_ins *tmp)
{
	long exec_code;

	exec_code = 0;
	while (tmp->params[j])
	{
		while (ft_whitespace(tmp->params[j]))
			j++;
		if (tmp->params[j] == 'r')
			exec_code++;
		else if (tmp->params[j] == DIRECT_CHAR)
		{
			if (tmp->id == 9 || tmp->id == 10 || tmp->id == 11
			|| tmp->id == 12 || tmp->id == 14 || tmp->id == 15)
				exec_code += 2;
			else
				exec_code += 4;
		}
		else
			exec_code += 2;
		while (tmp->params[j] != ',' && tmp->params[j] != '\0')
			j++;
		j++;
	}
	return (exec_code);
}

static long	exec_code_size(t_asm *tasm, long total_excode)
{
	t_ins	*tmp;
	t_label	*tmp_label;
	int		j;

	j = 0;
	tmp = tasm->instruction;
	tmp_label = tasm->labels;
	while (tmp)
	{
		j = 0;
		if (tmp->is_label == 1)
		{
			tmp_label->first_byte = total_excode;
			tmp_label = tmp_label->next;
		}
		if (tmp->id == 1 || tmp->id == 9
		|| tmp->id == 12 || tmp->id == 15)
			total_excode++;
		else
			total_excode += 2;
		total_excode += exec_count(j, tmp);
		tmp = tmp->next;
	}
	return (total_excode);
}

void		cor_generator(t_asm *tasm, char *av, t_header *header)
{
	int		len;
	long	total_excode;

	len = ft_strlen(header->comment) - 1;
	total_excode = exec_code_size(tasm, 0);
	tasm->fd = set_extension(av);
	if (tasm->fd == -1)
		return ;
	set_filename(tasm, header);
	set_comment(tasm, header, total_excode);
	write_params(tasm);
	ft_writeincolours(".Cor file ready\n", "green");
}
