/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 10:01:34 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/11 12:58:57 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] != '\0' && s1[i] == s2[i])
		{
			s1++;
			s2++;
		}
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (-1);
}
