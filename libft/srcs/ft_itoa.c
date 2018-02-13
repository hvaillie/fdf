/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:23:44 by hvaillie          #+#    #+#             */
/*   Updated: 2017/11/14 17:23:47 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void		itoa_recur(long long nl, char *s, size_t l)
{
	if (nl >= 10)
		itoa_recur(nl / 10, s, l - 1);
	s[l] = (nl % 10) + '0';
}

char			*ft_itoa(int n)
{
	long long	nl;
	char		*s;
	size_t		l;

	l = ft_lgint(n);
	if (!(s = ft_strnew(l)))
		return (NULL);
	nl = n;
	if (n < 0)
	{
		s[0] = '-';
		nl = -nl;
	}
	itoa_recur(nl, s, l - 1);
	return (s);
}
