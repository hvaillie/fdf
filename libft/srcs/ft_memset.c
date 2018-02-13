/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:47:49 by hvaillie          #+#    #+#             */
/*   Updated: 2017/11/11 12:49:02 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buc;
	unsigned char	cuc;
	size_t			i;

	buc = (unsigned char *)b;
	cuc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		buc[i] = cuc;
		i++;
	}
	return (b);
}
