/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_hex_up.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 16:51:34 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 12:31:44 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			check_behavior(t_param *param)
{
	if (param->lo != 0)
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

static void			print_hex(t_param *param, char *new,
								unsigned long long num, int w)
{
	int dif;

	dif = param->prec - ft_strlen(new);
	if (w > 0 && param->mflag == 0 && param->c != '0')
		print_width(param, w, param->c);
	if (param->hflag == 1 && num != 0 && param->prec != 0)
		ret_putstr(param, "0X");
	if (w > 0 && param->mflag == 0 && param->c == '0')
		print_width(param, w, param->c);
	while (dif > 0)
	{
		ret_putchar(param, '0');
		dif--;
	}
	if (param->prec != 0 && check_behavior(param))
		ret_putstr(param, new);
	if (w > 0 && w > (param->prec - param->width) && param->mflag == 1)
		print_width(param, w, ' ');
}

static int			set_w(t_param *param, char *new, unsigned long long num)
{
	int w;
	int dif;

	dif = param->prec - ft_strlen(new);
	w = param->width - ft_strlen(new);
	if (param->hflag == 1 && num != 0)
		w -= 2;
	if (dif > 0)
		w = w - (param->prec - ft_strlen(new));
	if (param->prec == 0)
		w++;
	return (w);
}

void				set_hex_up(va_list ap, t_param *param)
{
	char				*new;
	unsigned long long	num;
	int					w;

	num = get_num(ap, param);
	if (param->width > 0 && param->prec > 0)
		param->c = ' ';
	if (param->prec == -1)
		param->prec = 1;
	new = ft_itoa_base_up(num, 16);
	w = set_w(param, new, num);
	print_hex(param, new, num, w);
	free(new);
}
