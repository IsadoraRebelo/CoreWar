/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_unumber.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 15:48:06 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 11:31:51 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int					check_behavior(t_param *param)
{
	if (param->hflag != 0 || param->lo != 0)
	{
		ret_putchar(param, '\0');
		return (0);
	}
	return (1);
}

static unsigned long long	get_num(va_list ap, t_param *param)
{
	unsigned long long	num;

	if (param->l == 1 || param->ll == 1)
	{
		num = va_arg(ap, unsigned long long);
		return (num);
	}
	if (param->hh == 1)
	{
		num = (unsigned char)va_arg(ap, unsigned int);
		return (num);
	}
	if (param->h)
	{
		num = (unsigned short)va_arg(ap, unsigned int);
		return (num);
	}
	num = va_arg(ap, unsigned int);
	return (num);
}

static unsigned long long	ft_uintlen(unsigned long long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len = 1;
		nb = nb * -1;
	}
	if (nb < 10)
		return (len + 1);
	else
		return (len + 1 + ft_uintlen(nb / 10));
}

static void					print_unumber(t_param *param,
										unsigned long long num, int dif, int w)
{
	if (w > 0 && w > (param->prec - param->width) && param->mflag == 0)
		print_width(param, w, param->c);
	while (dif > 0)
	{
		ret_putchar(param, '0');
		dif--;
	}
	if (check_behavior(param))
		ret_putnbr_u(param, num);
	param->prec -= param->width;
	if (w > 0 && w > param->prec && param->mflag == 1)
		print_width(param, w, ' ');
}

void						set_unumber(va_list ap, t_param *param)
{
	unsigned long long	num;
	int					dif;
	int					w;

	if (param->width > 0 && param->prec > 0)
		param->c = ' ';
	if (param->prec == -1)
		param->prec = 1;
	num = get_num(ap, param);
	w = param->width - ft_uintlen(num);
	dif = param->prec - ft_uintlen(num);
	if (dif > 0)
		w -= dif;
	if (param->prec == 0)
		w++;
	print_unumber(param, num, dif, w);
}
