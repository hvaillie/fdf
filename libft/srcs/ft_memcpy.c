/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:45:26 by hvaillie          #+#    #+#             */
/*   Updated: 2017/11/11 13:45:30 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstuc;
	const unsigned char	*srcuc;
	size_t				i;

	dstuc = (unsigned char *)dst;
	srcuc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dstuc[i] = srcuc[i];
		i++;
	}
	return (dst);
}
