/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_part.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 15:05:31 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			set_struct(t_param *param)
{
	param->hflag = 0;
	param->mflag = 0;
	param->pflag = 0;
	param->c = ' ';
	param->sflag = 0;
	param->l = 0;
	param->ll = 0;
	param->lo = 0;
	param->h = 0;
	param->hh = 0;
	param->width = 0;
	param->prec = -1;
}

static int			length_mod(char *str, int i, t_param *param)
{
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		param->ll = 1;
		i++;
	}
	if (str[i] == 'l')
		param->l = 1;
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		param->hh = 1;
		i++;
	}
	if (str[i] == 'h')
		param->h = 1;
	if (str[i] == 'L')
		param->lo = 1;
	i++;
	return (i);
}

static int			choose_param(char *str, int i, va_list ap, t_param *param)
{
	if (str[i] == 'c')
		set_character(ap, param);
	else if (str[i] == 'i' || str[i] == 'd')
		set_number(ap, param);
	else if (str[i] == 's')
		set_string(ap, param);
	else if (str[i] == 'u')
		set_unumber(ap, param);
	else if (str[i] == 'o')
		set_octal(ap, param);
	else if (str[i] == 'f' && param->lo == 0)
		set_float(ap, param);
	else if (str[i] == 'f' && param->lo == 1)
		set_floatl(ap, param);
	else if (str[i] == 'x')
		set_hex(ap, param);
	else if (str[i] == 'X')
		set_hex_up(ap, param);
	else if (str[i] == 'p')
		set_pointer(ap, param);
	else if (str[i] == '%')
		set_percent(param);
	else
		return (0);
	return (1);
}

int					str_part(char *str, int i, va_list ap, t_param *param)
{
	set_struct(param);
	while (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '0'
		|| str[i] == '#')
	{
		flags(str[i], param);
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
		i = width(str, i, param);
	if (str[i] == '.')
		i = set_prec(str, i, param);
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
		i = length_mod(str, i, param);
	if (choose_param(str, i, ap, param))
		i++;
	return (i);
}
