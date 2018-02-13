/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <hvaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:26:12 by hvaillie          #+#    #+#             */
/*   Updated: 2017/11/18 17:19:27 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;
	t_list	*current;

	if (!lst || !f)
		return (NULL);
	first = NULL;
	while (lst)
	{
		if (!(new = f(ft_lstnew(lst->content, lst->content_size))))
			return (NULL);
		if (first)
			ft_lstaddlast(&current, new);
		else
		{
			first = new;
			current = new;
		}
		lst = lst->next;
	}
	return (first);
}
