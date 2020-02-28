/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 11:50:48 by dfreire        #+#    #+#                */
/*   Updated: 2020/02/24 13:36:59 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "../op.h"
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# define BY2	65536
# define BY4	4294967296

/*
** Define Errors:
*/

# define ERROR_USAGE 1
# define ERROR_EXTENSION 2
# define ERROR_FILE 3
# define ERROR_NAME 4
# define ERROR_COMMENT 5
# define ERROR_INVALIDCH 6
# define ERROR_PARAM 7
# define ERROR_INSTRUCTION 8

typedef struct	s_ins
{
	char			*params;
	int				nb_params;
	int				id;
	int				is_label;
	struct s_ins	*next;
}				t_ins;

typedef struct	s_label
{
	char			*labels;
	int				index;
	int				first_byte;
	int				nb_labels;
	struct s_label	*next;
}				t_label;

typedef struct	s_asm
{
	int				nb_params;
	int				index;
	int				is_label;
	int				cursor;
	int				arg_cursor;
	int				fd;
	int				nb_labels;
	t_ins			*instruction;
	t_label			*labels;
	t_op			op_tab[17];
	t_list			*file;
}				t_asm;

/*
** Create Lists
*/
void			read_list(t_asm *tasm, t_header *header);
void			set_instructions(char *line, t_asm *tasm);
void			set_params(t_asm *tasm, char *line, int i, int nb_params);
void			get_params(char *line, t_ins *ins);
void			get_labels(char *line, t_label *label, t_asm *tasm, int len);
t_label			*get_current_label(t_asm *tasm);
t_ins			*get_current_ins(t_asm *tasm);

/*
** Checkers
*/
void			check_name(char *line, t_header *header);
void			check_comment(char *line, t_header *header);
void			check_params(t_asm *tasm);
int				check_if_label(t_asm *tasm, char *line, int i);
int				check_first_arg(t_asm *tasm, char *line, int i, int id);
int				check_second_arg(t_asm *tasm, char *line, int i, int id);
void			check_third_arg(t_asm *tasm, char *line, int i, int id);

/*
** Translation
*/
void			ft_puthexa_fd(long code, int fd);
void			cor_generator(t_asm *tasm, char *av, t_header *header);
void			set_filename(t_asm *tasm, t_header *header);
void			set_comment(t_asm *tasm, t_header *header, long total_excode);
void			write_params(t_asm *tasm);
void			translate_params(t_asm *tasm, t_ins *tmp, int j);
void			set_direct(t_asm *tasm, char *param, t_ins *tmp);
int				set_labels(t_asm *tasm, char *param);

/*
** Other functions
*/
void			set_op(t_asm *tasm);
int				set_max(int id);
void			free_structs(t_label *label, t_header *header, t_asm *tasm);
void			error_message(int id, char *line);
void			free_double_arr(char **tmp);
void			dup_param(char *param, char *temp);

#endif
