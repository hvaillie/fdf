/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 19:40:22 by hvaillie          #+#    #+#             */
/*   Updated: 2018/02/06 19:40:25 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	int 	nbpoint;

	if (!(nbpoint = copy_check_file(argc, argv)))
	{
		ft_putstr("Invalid file\n");
		return (-1);
	}
	//load_file()
	return (0);
}
