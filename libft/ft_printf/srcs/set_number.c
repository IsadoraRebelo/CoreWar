/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_number.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:43:26 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 11:36:45 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			check_behavior(t_param *param)
{
	if (param->hflag != 0 || param->lo != 0)
	{
		ret_putchar(param, '\0');
		return (0);
	}
	return (1);
}

static long long	get_num(va_list ap, t_param *param)
{
	long long num;

	if (param->l == 1 || param->ll == 1)
	{
		num = va_arg(ap, long long);
		return (num);
	}
	if (param->hh == 1)
	{
		num = (char)va_arg(ap, int);
		return (num);
	}
	if (param->h)
	{
		num = (short)va_arg(ap, int);
		return (num);
	}
	num = va_arg(ap, int);
	return (num);
}

static int			set_w(t_param *param, long long num)
{
	int			w;

	w = param->width - ft_intlen(num);
	if (param->prec >= ft_intlen(num))
	{
		w = w - (param->prec - ft_intlen(num));
		if (num < 0)
			w--;
	}
	if (param->sflag == 1 && param->pflag == 0 && num >= 0)
	{
		ret_putchar(param, ' ');
		w--;
	}
	if (param->pflag == 1 && num >= 0)
		w--;
	if (param->prec == 0 && num == 0)
		w++;
	return (w);
}

static void			print_number(t_param *param, long long num, int w)
{
	if (w > 0 && w > (param->prec - param->width) && param->mflag == 0
		&& param->c == ' ')
		print_width(param, w, param->c);
	if (param->pflag == 1 && num >= 0)
		ret_putchar(param, '+');
	if (num < 0 && num > LONG_MIN)
	{
		num *= -1;
		ret_putchar(param, '-');
	}
	if (w > 0 && w > (param->prec - param->width) && param->mflag == 0
		&& param->c == '0')
		print_width(param, w, param->c);
	while ((param->prec) > ft_intlen(num))
	{
		ret_putchar(param, '0');
		param->prec--;
	}
	if (param->prec == 0 && num == 0)
		return ;
	if (check_behavior(param) || !(param->prec == 0 && num == 0))
		ret_putnbr(param, num);
}

void				set_number(va_list ap, t_param *param)
{
	long long	num;
	int			w;

	if (param->prec == -1)
		param->prec = 1;
	num = get_num(ap, param);
	w = set_w(param, num);
	if (param->prec > 1 || param->prec == 0)
		param->c = ' ';
	print_number(param, num, w);
	param->prec -= param->width;
	if (w > 0 && w > param->prec && param->mflag == 1)
		print_width(param, w, ' ');
}
