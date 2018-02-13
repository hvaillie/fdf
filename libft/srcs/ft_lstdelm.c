/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <hvaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:01:57 by hvaillie          #+#    #+#             */
/*   Updated: 2017/12/04 17:05:18 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelmaillon(t_list **begin_list, t_list *lst)
{
	t_list	*prev;
	t_list	*next;

	if (begin_list && *begin_list && lst)
	{
		prev = *begin_list;
		next = *begin_list;
		while (next)
		{
			if (next == lst || *begin_list == lst)
			{
				if (*begin_list == lst)
					*begin_list = next->next;
				else
					prev->next = next->next;
				free(next->content);
				free(next);
				return ;
			}
			prev = next;
			next = prev->next;
		}
	}
}
