/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_whitespace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 14:50:50 by ihering-       #+#    #+#                */
/*   Updated: 2020/01/06 14:50:59 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_whitespace(char s)
{
	if (s == '\n' || s == ' ' || s == '\t' ||
		s == '\v' || s == '\r' || s == '\f')
		return (1);
	return (0);
}
