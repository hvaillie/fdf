/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:37:26 by hvaillie          #+#    #+#             */
/*   Updated: 2017/11/10 19:14:41 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnchr(const char *s, int c, int size)
{
	char	cc;
	int		i;

	cc = (char)c;
	i = 0;
	while (s[i] && i < size)
	{
		if (s[i] == cc)
			return ((char*)&s[i]);
		i++;
	}
	return (NULL);
}
