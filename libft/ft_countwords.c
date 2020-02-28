/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_countwords.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 14:43:53 by ihering-       #+#    #+#                */
/*   Updated: 2020/01/06 14:44:05 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_isspace(char c)
{
	while (c == '\n' || c == ' ' || c == '\t' || c == '\v'
	|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

static int	is_last_space(char const *s, int i)
{
	while (ft_isspace(s[i]))
	{
		if (ft_isspace(s[i]) && s[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int			ft_countwords(char const *s)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	if (!(ft_isspace(s[0])))
	{
		nb++;
		i++;
	}
	while (s[i] != '\0')
	{
		if (!(ft_isspace(s[i - 1])) && ft_isspace(s[i]))
		{
			if (!is_last_space(s, i))
				nb++;
			i++;
		}
		i++;
	}
	return (nb);
}
