/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_prec.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 11:42:01 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		check_nul(char c, t_param *param)
{
	if (c < '0' || c > '9')
	{
		param->prec = 0;
		return (1);
	}
	return (0);
}

static void		set_num(char *num, char *str, int j, int len)
{
	int l;

	l = 0;
	while (l < len)
	{
		num[l] = str[j];
		j++;
		l++;
	}
}

int				set_prec(char *str, int i, t_param *param)
{
	int		len;
	int		j;
	char	*num;

	len = 0;
	j = i + 1;
	i++;
	if (check_nul(str[i], param))
		return (i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		len++;
		i++;
	}
	num = ft_strnew(len);
	set_num(num, str, j, len);
	param->prec = ft_atoi(num);
	free(num);
	return (i);
}
