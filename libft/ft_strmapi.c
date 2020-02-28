/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 10:43:32 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/27 11:00:06 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*fstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen((char *)s);
	fstr = ft_strnew(j);
	if (fstr == NULL)
		return (NULL);
	if (s && f)
	{
		while (s[i] != '\0')
		{
			fstr[i] = f(i, s[i]);
			i++;
		}
		return (fstr);
	}
	return (NULL);
}
