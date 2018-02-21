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
# define ESCAPE_KEY 53
# define NUM9_KEY 92
# define NUM8_KEY 91
# define NUM7_KEY 89
# define NUM6_KEY 88
# define NUM5_KEY 87
# define NUM4_KEY 86
# define NUM3_KEY 85
# define NUM2_KEY 84
# define NUM1_KEY 83
# define NUM0_KEY 82
# define ARROW_LEFT_KEY 123
# define ARROW_RIGHT_KEY 124
# define ARROW_DOWN_KEY 125
# define ARROW_UP_KEY 126
# define A_KEY 0
# define S_KEY 1
# define Z_KEY 6
# define X_KEY 7
# define Q_KEY 12
# define W_KEY 13
# define WINDOW_SIZE_H 2000
# define WINDOW_SIZE_V 1200
# define IMAGE_SIZE_H 1500
# define IMAGE_SIZE_V 1200
# define DEFSZX 20
# define DEFSZY 20
# define DEFSZZ 2
# define DEFSHIFT 0
# define DEFROX 0
# define DEFROY 0
# define DEFROZ 0
# define KP 1
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00

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

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		wszh;
	int		wszv;
	int		iszh;
	int		iszv;
	int 	bpp;
	int 	szl;
	int 	endian;
	t_point	po;
	t_point	pd;
	int		rgb;
	int		shift;
	int		max;
	int		szx;
	int		szy;
	int		szz;
	int		rox;
	int		roy;
	int		roz;
	t_fdf	*tf;
}				t_mlx;

typedef struct	s_draw
{
	int				diffx;
	int				diffy;
	float			incx;
	float			incy;
	unsigned int	color;
	unsigned char	octets[4];
	int				loops;
	t_point			p;
}				t_draw;

int				copy_check_file(int argc, char **argv, t_fdf *tf);
int				alloc_map(t_fdf *tf);
void			display_map(t_fdf *tf);
void			free_map(t_fdf *tf);
int				load_file(t_fdf *tf);
void			setmlx(t_fdf *tf);
int 			key_hook(int key, void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				expose_hook(void *param);
int				loop_hook(void *param);
void 			draw_map(t_mlx *tm);
void 			display_window(t_mlx *tm);

#endif
