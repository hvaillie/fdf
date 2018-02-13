/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:47:52 by hvaillie          #+#    #+#             */
/*   Updated: 2017/11/11 15:47:58 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	char		*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst < src && n > 0)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (dst > src && n > 0)
	{
		i = n;
		while (i != 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dst);
}
