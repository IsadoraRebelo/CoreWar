/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 14:26:09 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/27 11:00:06 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*res;

	sign = 0;
	len = ft_intlen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		sign = 1;
	res = ft_strnew(len);
	len = 0;
	if (!res)
		return (NULL);
	while (n / 10 != 0 || n % 10 != 0)
	{
		res[len] = ft_abs(n % 10) + '0';
		n /= 10;
		len++;
	}
	return (ft_strend(res, sign, len));
}
