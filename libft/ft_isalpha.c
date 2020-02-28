/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 11:52:24 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/27 11:02:01 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isalpha(int c)
{
	return (ft_tolower(c) != c || ft_toupper(c) != c);
}
