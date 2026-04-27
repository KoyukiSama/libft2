/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:37:56 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/27 17:49:37 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_cont;
	t_list	*new_node;
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_cont = f(lst->content);
		if (!new_cont)
			return (ft_lstclear(&new_lst, del), NULL);
		new_node = ft_lstnew(new_cont);
		if (!new_node)
			return (ft_lstclear(&new_lst, del), del(new_cont), NULL);
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
