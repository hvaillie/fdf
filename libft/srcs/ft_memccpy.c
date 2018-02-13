/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:51:51 by hvaillie          #+#    #+#             */
/*   Updated: 2017/11/11 14:51:55 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dstuc;
	const unsigned char	*srcuc;
	unsigned char		cuc;
	size_t				i;

	dstuc = (unsigned char *)dst;
	srcuc = (const unsigned char *)src;
	cuc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dstuc[i] = srcuc[i];
		if (srcuc[i] == cuc)
			return (&dstuc[i + 1]);
		i++;
	}
	return (NULL);
}
