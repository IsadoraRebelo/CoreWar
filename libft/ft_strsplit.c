/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 15:32:04 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/11 12:48:58 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	int		wrdcount;
	char	**word;

	i = 0;
	wrdcount = ft_wordcount(s, c);
	word = (char **)malloc(sizeof(char *) * (wrdcount + 1));
	if (!word)
		return (NULL);
	word[wrdcount] = NULL;
	j = 0;
	while (j < wrdcount)
	{
		if (s[i] != c)
		{
			len = ft_strnlen((char *)s, i, c);
			word[j] = ft_strsub(s, i, len - i);
			j++;
			i = len - 1;
		}
		i++;
	}
	return (word);
}
