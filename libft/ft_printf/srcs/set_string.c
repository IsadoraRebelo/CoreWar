/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_string.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 15:13:47 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 14:00:17 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		alt_putstr(char *str, t_param *param)
{
	int i;
	int max;

	i = 0;
	max = 0;
	while (str[i] != '\0' && (max < param->prec))
	{
		ret_putchar(param, str[i]);
		i++;
		max++;
	}
}

static void		print_string(t_param *param, char *str, int w)
{
	if (w > 0 && param->mflag == 0)
		print_width(param, w, param->c);
	if (param->prec != 0)
		alt_putstr(str, param);
	if (w > 0 && param->mflag == 1)
		print_width(param, w, ' ');
}

void			set_string(va_list ap, t_param *param)
{
	int		w;
	int		len;
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	w = param->width;
	if (param->prec == -1)
		param->prec = len;
	if (param->prec != len)
		w -= param->prec;
	if (len == 0)
		w = param->width;
	if (param->prec >= len)
		w = param->width - len;
	print_string(param, str, w);
}
