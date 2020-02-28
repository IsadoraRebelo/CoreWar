/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 15:04:31 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			width(char *str, int i, t_param *param)
{
	int		j;
	int		len;
	char	*num;

	j = i;
	len = 0;
	while (str[j] >= '0' && str[j] <= '9')
	{
		len++;
		j++;
	}
	num = ft_strnew(len);
	j = 0;
	while (j < len)
	{
		num[j] = str[i];
		j++;
		i++;
	}
	param->width = ft_atoi(num);
	free(num);
	return (i);
}
