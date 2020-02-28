/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 18:12:40 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/27 11:00:06 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void *, size_t))
{
	if (del == NULL)
		return ;
	if (*alst)
	{
		del((*alst)->content, sizeof(*alst));
		free(*alst);
		*alst = NULL;
	}
}
