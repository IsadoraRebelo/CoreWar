/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_octal.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:11:29 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 10:57:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			check_behavior(t_param *param)
{
	if (param->pflag != 0 || param->sflag != 0 || param->lo != 0)
	{
		ret_putchar(param, '\0');
		return (0);
	}
	return (1);
}

static long long	get_num(va_list ap, t_param *param)
{
	unsigned long long num;

	if (param->l == 1 || param->ll == 1)
	{
		num = va_arg(ap, unsigned long long);
		return (num);
	}
	if (param->hh == 1)
	{
		num = (unsigned char)(unsigned int)va_arg(ap, int);
		return (num);
	}
	if (param->h)
	{
		num = (unsigned short)va_arg(ap, unsigned int);
		return (num);
	}
	num = (unsigned int)va_arg(ap, int);
	return (num);
}

static void			print_octal(t_param *param, char *new, int dif, int w)
{
	if (w > 0 && (w > (param->prec - param->width)) && param->mflag == 0)
		print_width(param, w, param->c);
	if (param->hflag == 1 && dif < 1)
		ret_putchar(param, '0');
	while (dif > 0)
	{
		ret_putchar(param, '0');
		dif--;
	}
	if (!(param->hflag == 1 && *new == '0') && check_behavior(param) &&
		!(param->prec == 0 && *new == '0'))
		ret_putstr(param, new);
	if (w > 0 && (w > (param->prec - param->width)) && param->mflag == 1)
		print_width(param, w, ' ');
}

void				set_octal(va_list ap, t_param *param)
{
	char				*new;
	int					dif;
	unsigned long long	num;
	int					w;

	num = get_num(ap, param);
	if (param->width > 0 && param->prec > 0)
		param->c = ' ';
	if (param->prec == -1)
		param->prec = 1;
	new = ft_itoa_base(num, 8);
	dif = (param->prec) - ft_strlen(new);
	w = param->width - ft_strlen(new) - param->hflag - param->pflag;
	if (param->prec == 0 && *new == '0')
		w++;
	if (dif > 0)
		w -= dif;
	if (param->hflag == 1 && num == 0)
		w++;
	print_octal(param, new, dif, w);
	free(new);
}
