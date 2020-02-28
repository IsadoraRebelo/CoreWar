/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strend.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 10:29:06 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/27 11:00:06 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strend(char *res, int neg, int len)
{
	if (neg == 1)
	{
		res[len] = '-';
		len++;
	}
	res[len] = '\0';
	res = ft_strrev(res);
	return (res);
}
