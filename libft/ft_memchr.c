/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 14:15:04 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/27 11:00:06 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*res;
	unsigned char	c2;
	size_t			i;

	i = 0;
	res = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (n > 0)
	{
		if (res[i] == c2)
			return (res + i);
		i++;
		n--;
	}
	return (NULL);
}
