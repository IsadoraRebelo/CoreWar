/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 11:40:57 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/27 11:00:06 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*res;

	if (!lst)
		return (NULL);
	list = f(lst);
	res = list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		list->next = f(lst);
		if (f(list) == NULL)
			return (NULL);
		list = list->next;
	}
	return (res);
}
