/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_pointer.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 17:23:46 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/11 14:14:16 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int					check_behavior(t_param *param)
{
	if (param->pflag != 0 || param->hflag != 0 || param->sflag != 0)
	{
		ret_putchar(param, '\0');
		return (0);
	}
	return (1);
}

static void					print_prec(t_param *param, char *new)
{
	int		len;

	len = param->prec - ft_strlen(new);
	while (len > 0)
	{
		ret_putchar(param, '0');
		len--;
	}
}

void						set_pointer(va_list ap, t_param *param)
{
	char					*new;
	unsigned long long		num;
	int						w;

	num = va_arg(ap, unsigned long long);
	new = ft_itoa_base(num, 16);
	w = param->width - ft_strlen(new) - 2;
	if (w > 0 && param->mflag == 0)
		print_width(param, w, ' ');
	ret_putstr(param, "0x");
	print_prec(param, new);
	if (!(param->prec == 0 && num == 0) && check_behavior(param))
		ret_putstr(param, new);
	if (w > 0 && param->mflag == 1)
		print_width(param, w, ' ');
	free(new);
}
