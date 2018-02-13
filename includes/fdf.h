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

# define PROTECT(x,y) if(!x) return (y);
# define OK 1
# define KO 0
# define OK_MAIN 0
# define KO_MAIN -1
# define TEMPFILE "temp.fdf"

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		w;
	int		rgb;
}				t_point;

typedef struct	s_fdf
{
	int				nbpt;
	int				nbrow;
	t_point			**tp;

}				t_fdf;

int				copy_check_file(int argc, char **argv, t_fdf *tf);
int				alloc_map(t_fdf *tf);
void			display_map(t_fdf *tf);
void			free_map(t_fdf *tf);
int				load_file(t_fdf *tf);

#endif
