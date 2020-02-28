/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dup_param.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 13:25:06 by lsmienk        #+#    #+#                */
/*   Updated: 2020/02/24 13:25:31 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	dup_param(char *param, char *temp)
{
	temp = ft_strdup(temp);
	free(param);
	param = temp;
}
