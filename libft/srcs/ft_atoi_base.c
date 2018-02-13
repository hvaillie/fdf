/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:26:19 by hvaillie          #+#    #+#             */
/*   Updated: 2018/02/02 18:26:26 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	check_base(char *str, int base, char basex[16])
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (base == 16 && str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	else if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] != ' ')
	{
		if (!ft_strnchr(basex, (int)str[i], base))
			return (0);
		i++;
	}
	while (str[i] == ' ')
		i++;
	return ((str[i]) ? 0 : 1);
}

static int	get_return(unsigned long long nb, int sign)
{
	if (nb >= 9223372036854775807 && sign == 1)
		return (-1);
	if (nb > 9223372036854775807 && sign == -1)
		return (0);
	return (nb * sign);
}

int			ft_atoi_base(const char *str, int base)
{
	static char			basex[16] = "0123456789ABCDEF";
	int					i;
	int					basepow;
	unsigned long long	nb;
	int					sign;

	if (!str || base < 2 || base > 16 || !check_base((char*)str, base, basex))
		return (0);
	sign = 1;
	i = ft_strlen(str) - 1;
	while (str[i] == ' ')
		i--;
	basepow = 1;
	nb = 0;
	while (i >= 0 && str[i] != ' ' && str[i] != 'x'
			&& str[i] != '-' && str[i] != '+')
	{
		nb += ft_strchrx(basex, (int)str[i]) * basepow;
		basepow *= base;
		i--;
	}
	if (str[i] == '-')
		sign = -1;
	return (get_return(nb, sign));
}
