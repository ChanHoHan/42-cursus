/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:04:08 by chan              #+#    #+#             */
/*   Updated: 2021/01/04 12:13:51 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*new;

	if (!lst || !f || !(new = ft_lstnew(f(lst->content))))
		return (NULL);
	a = new;
	a->next = NULL;
	lst = lst->next;
	while (lst)
	{
		if (!(a->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		a = a->next;
		lst = lst->next;
	}
	return (new);
}
