/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 15:08:00 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/11 12:49:51 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t start;
	size_t end;

	start = 0;
	end = 0;
	if (s)
	{
		end = ft_strlen(s) - 1;
		if (s == NULL)
			return (0);
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		if (s[start] == '\0')
			return (ft_strnew(0));
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
	}
	return (ft_strsub(s, start, end - start + 1));
}
