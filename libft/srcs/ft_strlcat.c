/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 17:42:51 by hvaillie          #+#    #+#             */
/*   Updated: 2017/11/10 19:04:51 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		lgd;
	size_t		j;
	size_t		lgs;

	lgd = 0;
	while (dest[lgd] != '\0')
		lgd++;
	lgs = 0;
	while (src[lgs] != '\0')
		lgs++;
	j = 0;
	while (src[j] != '\0' && lgd + j + 1 < size)
	{
		dest[lgd + j] = src[j];
		j++;
	}
	dest[lgd + j] = '\0';
	if (size < lgd)
		return (size + lgs);
	while (src[j] != '\0')
		j++;
	return (lgd + j);
}
