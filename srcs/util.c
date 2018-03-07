/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:38:10 by hvaillie          #+#    #+#             */
/*   Updated: 2018/03/07 16:38:13 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*concat_legend(char *str, char *l, int v, char *(*f)(int value))
{
	char	*vx;

	str = ft_strcat(str, l);
	vx = f(v);
	str = ft_strcat(str, vx);
	free(vx);
	return (str);
}

int			min4(int i[4])
{
	return (ft_min(ft_min(i[0], i[1]), ft_min(i[2], i[3])));
}

int			max4(int i[4])
{
	return (ft_max(ft_max(i[0], i[1]), ft_max(i[2], i[3])));
}
