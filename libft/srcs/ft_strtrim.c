/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:27:29 by hvaillie          #+#    #+#             */
/*   Updated: 2017/11/13 18:27:31 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		l;
	char	*strim;

	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	while (l - 1 >= 0 && ft_issepar((int)s[l - 1]))
		l--;
	i = 0;
	while (s[i] != '\0' && ft_issepar((int)s[i]) && l > 0)
	{
		i++;
		l--;
	}
	strim = ft_strnew(l);
	if (strim == NULL)
		return (NULL);
	return (ft_memcpy(strim, &s[i], l));
}
