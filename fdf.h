/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:21:01 by hvaillie          #+#    #+#             */
/*   Updated: 2018/01/23 20:21:06 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ESCAPE_KEY 53
# define RED 	0xFF0000
# define GREEN 	0x00FF00
# define BLUE 	0x0000FF
# define BLACK	0x000000
# define WHITE	0xFFFFFF

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

#endif
