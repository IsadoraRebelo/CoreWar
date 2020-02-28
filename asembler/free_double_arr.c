/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_double_arr.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 12:03:00 by lsmienk        #+#    #+#                */
/*   Updated: 2020/02/24 12:03:35 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_double_arr(char **tmp)
{
	int		i;

	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(tmp);
	tmp = NULL;
}
