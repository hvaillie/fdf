/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:13:05 by hvaillie          #+#    #+#             */
/*   Updated: 2017/11/13 18:13:09 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (s3 != NULL)
	{
		ft_strcat(s3, s1);
		ft_strcat(s3, s2);
	}
	return (s3);
}
