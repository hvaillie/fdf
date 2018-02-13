/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 14:21:32 by hvaillie          #+#    #+#             */
/*   Updated: 2017/09/14 15:29:15 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int		is_sep(char s, char c)
{
	return ((s == c) ? 1 : 0);
}

static int		countstr(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (is_sep(s[i], c))
			i++;
		if (s[i] != '\0')
			nb++;
		while (is_sep(s[i], c) == 0 && s[i])
			i++;
	}
	return (nb);
}

static char		*addstr(char const *s, char c, int *i)
{
	char	*str;
	int		j;

	j = *i;
	while (s[j] && !(is_sep(s[j], c)))
		j++;
	if (!(str = ft_strnew(j)))
		return (NULL);
	j = 0;
	while (s[*i] && !(is_sep(s[*i], c)))
	{
		str[j] = s[*i];
		j++;
		*i += 1;
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		i;
	int		j;
	int		nbs;

	if (!s)
		return (NULL);
	nbs = countstr(s, c);
	if (!(t = (char**)malloc(sizeof(t) * (nbs + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < nbs)
	{
		while (is_sep(s[i], c))
			i++;
		if (!(t[j] = addstr(s, c, &i)))
			return (NULL);
		j++;
	}
	t[j] = NULL;
	return (t);
}
