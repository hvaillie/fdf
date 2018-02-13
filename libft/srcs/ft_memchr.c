/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:56:40 by hvaillie          #+#    #+#             */
/*   Updated: 2017/11/11 16:56:43 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*suc;
	unsigned char	cuc;
	size_t			i;

	suc = (unsigned char *)s;
	cuc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (suc[i] == cuc)
			return (&suc[i]);
		i++;
	}
	return (NULL);
}
