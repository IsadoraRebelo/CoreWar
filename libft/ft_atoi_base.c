/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 16:46:23 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/27 10:54:53 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_base_test(const char c)
{
	int	nb;

	if (c >= '0' && c <= '9')
		nb = c - '0';
	else if (c >= 'a' && c <= 'z')
		nb = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		nb = c - 'A' + 10;
	else
		nb = -1;
	return (nb);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int			nb;
	int			neg;
	char		i;

	i = 0;
	neg = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	i = ft_base_test((char)*str);
	while (i >= 0 && *str && i <= str_base)
	{
		nb = nb * str_base + i;
		str++;
		i = ft_base_test((char)*str);
	}
	if (nb < 0)
		return (-nb);
	return (nb);
}
