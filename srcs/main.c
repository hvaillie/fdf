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
	t_fdf	tf;

	tf.nbpt = 0;
	tf.nbrow = 0;
	if (!(copy_check_file(argc, argv, &tf)))
	{
		ft_putendl("Invalid file");
		return (KO_MAIN);
	}
	PROTECT(alloc_map(&tf), KO_MAIN);
	PROTECT(load_file(&tf), KO_MAIN);
	display_map(&tf);
	setmlx(&tf);
	free_map(&tf);
	return (OK_MAIN);
}
