/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:48:33 by exam              #+#    #+#             */
/*   Updated: 2018/01/30 13:21:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static char	get_base(int pos)
{
	return ((pos < 10) ? '0' + pos : 'A' + (pos - 10));
}

char		*ft_itoa_base(int value, int base)
{
	char			tmp[32];
	char			*str;
	int				i;
	int				j;
	unsigned int	nb;

	if (base < 2 || base > 16)
		return (NULL);
	i = 0;
	nb = (value < 0) ? -value : value;
	while (nb >= (unsigned int)base)
	{
		tmp[i++] = get_base(nb % base);
		nb = nb / base;
	}
	tmp[i] = get_base(nb);
	if (base == 10 && value < 0)
		tmp[++i] = '-';
	j = 0;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i >= 0)
		str[j++] = tmp[i--];
	return (str);
}
