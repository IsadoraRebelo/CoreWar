/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comment_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 15:03:12 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/21 13:19:51 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	put_comment(int index, long total_excode,
						t_header *header, t_asm *tasm)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (j < index)
	{
		ft_putchar_fd(0, tasm->fd);
		j++;
	}
	if (total_excode != 0)
		ft_puthexa_fd(total_excode, tasm->fd);
	while (header->comment[i] != '\0')
	{
		ft_putchar_fd(header->comment[i], tasm->fd);
		i++;
	}
	while (i < COMMENT_LENGTH + 4)
	{
		ft_putchar_fd(0x0, tasm->fd);
		i++;
	}
}

void		set_comment(t_asm *tasm, t_header *header, long total_excode)
{
	int		count;
	int		index;
	long	nb_temp;

	index = 0;
	count = 0;
	while (count != 3)
	{
		ft_putchar_fd(0x0, tasm->fd);
		count++;
	}
	nb_temp = total_excode;
	while (nb_temp != 0)
	{
		nb_temp = nb_temp / 256;
		index++;
	}
	index = 4 - index;
	put_comment(index, total_excode, header, tasm);
}

static void	write_comment(char *line, t_header *header, int i, int len)
{
	int	j;

	j = 0;
	while (i < len - 1)
	{
		header->comment[j] = line[i];
		j++;
		i++;
	}
	header->comment[j] = '\0';
}

void		check_comment(char *line, t_header *header)
{
	int	len;
	int i;

	len = ft_strlen(line);
	i = ft_strlen(COMMENT_CMD_STRING);
	if (!ft_strnstr(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		error_message(ERROR_COMMENT, line);
	while (line[i] && (line[i] == ' ' || line[i] == '\n' || line[i] == '\t'))
		i++;
	if (!line[i] || len - i - (int)ft_strlen(COMMENT_CMD_STRING) - 3 >
	COMMENT_LENGTH || i == (int)ft_strlen(COMMENT_CMD_STRING) ||
	line[i] != '"' || line[len - 1] != '"')
		error_message(ERROR_COMMENT, line);
	i++;
	write_comment(line, header, i, len);
}
