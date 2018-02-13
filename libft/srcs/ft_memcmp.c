/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:23:24 by hvaillie          #+#    #+#             */
/*   Updated: 2017/11/11 17:23:27 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1uc;
	const unsigned char	*s2uc;

	s1uc = (const unsigned char	*)s1;
	s2uc = (const unsigned char	*)s2;
	while (n--)
		if (*s1uc++ != *s2uc++)
			return (*--s1uc - *--s2uc);
	return (0);
}
