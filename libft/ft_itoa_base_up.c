/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_up.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 16:57:59 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/27 11:00:06 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_llilen(unsigned long long nb, int base)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

static int		ft_sign(unsigned long long nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

char			*ft_itoa_base_up(unsigned long long nb, int base)
{
	int		len;
	int		i;
	char	*res;

	i = 1;
	if (nb == 0)
		return (ft_strdup("0"));
	ft_sign(nb);
	len = ft_llilen(nb, base);
	res = ft_strnew(len + ft_sign(nb));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (ft_sign(nb) == 1)
		res[len - i] = '-';
	while (nb != 0)
	{
		res[len - i] = BS[nb % base];
		res[len - i] = ft_toupper(res[len - i]);
		nb /= base;
		i++;
	}
	res = ft_strrev(res);
	return (ft_strend(res, ft_sign(nb), len));
}
