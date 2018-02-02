#include <mlx.h>
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libft/includes/libft.h"


int 	key_hook(int key, void *param) {
	fprintf(stdout, "Key=%d\n", key);
	if (key == ESCAPE_KEY)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	fprintf(stdout, "Mouse Button=%d ,x=%d ,y=%d\n", button, x, y);
	return (0);
}

int		expose_hook(void *param)
{
	fprintf(stdout, "Expose\n");
	return (0);
}

int		loop_hook(void *param)
{
	return (0);
}

void	proj(char type_projection, t_mlx *tm)
{
	if (type_projection == 'p')
	{
		tm->po.x += tm->po.z * K_COEFPARA;
		tm->po.y += tm->po.z * K_COEFPARA / 2;
	}
	else if (type_projection == 'i')
	{
		tm->po.x = (tm->po.x * K_COEFISO1) - (tm->po.y * K_COEFISO2);
		tm->po.y = tm->po.z + (K_COEFISO1 / 2 * tm->po.x) + (K_COEFISO2 / 2 * tm->po.y);
	}
}
int 	draw_line(t_mlx *tm)
{
	t_draw			td;
	int				i;
	int				j;

	td.diffx = tm->pd.x - tm->po.x;
	td.diffy = tm->pd.y - tm->po.y;
	td.loops = ft_max(ft_abs(td.diffx), ft_abs(td.diffy));
	td.incx = (float)td.diffx / td.loops;
	td.incy = (float)td.diffy / td.loops;
	td.color = mlx_get_color_value(tm->mlx_ptr, tm->rgb);
	td.octets[0] = td.color >> 0;
	td.octets[1] = td.color >> 8;
	td.octets[2] = td.color >> 16;
	td.octets[3] = td.color >> 24;

	// fprintf(stdout, "loop=%d, incxs=%f, incy=%f, \
	//  				color=(%d) %.2x %.2x %.2x %.2x\n",
	// 		td.loops, td.incx, td.incy, td.color,
	// 		td.octets[0], td.octets[1], td.octets[2], td.octets[3]);
	// fprintf(stdout, "Orig=(%d,%d), Dest=(%d,%d)\n",
	//  		tm->po.x, tm->po.y, tm->pd.x, tm->pd.y);
	proj('p', tm);
	i = 0;
	while (i <= td.loops)
	{
		td.p.x = tm->po.x + (td.incx * i);
		td.p.y = tm->po.y + (td.incy * i);
		//fprintf(stdout, "point %d=(%d,%d)\n", i, x, y);
		j = 0;
		while(j < tm->bpp / 8)
		{
			tm->img_data[(tm->szl * td.p.y) + (tm->bpp / 8 * td.p.x) + j + tm->middle]
			 	= td.octets[j];
			j++;
		}
		i++;
	}
	return (td.loops);
}

void		draw_h(t_mlx *tm, t_fdf *tf)
{
	int				i;
	int				j;

	j = 0;
	while (j < tf->y)
	{
		i = 0;
		while (i < tf->x - 1)
		{
			tm->po.x = i * K_SPACE;
			tm->po.y = j * K_SPACE;
			tm->pd.x = (i + 1) * K_SPACE;
			tm->pd.y = j * K_SPACE;
			//tm.rgb = tf->tfe[(i * tf->x) + j].rgb;
			tm->rgb = RED;
			draw_line(tm);
			i++;
		}
		j++;
	}
}

void 		draw_v (t_mlx *tm, t_fdf *tf)
{
	int				i;
	int				j;

	i = 0;
	while (i < tf->x)
	{
		j = 0;
		while (j < tf->y - 1)
		{
			tm->po.x = i * K_SPACE;
			tm->po.y = j * K_SPACE;
			tm->pd.x = i * K_SPACE;
			tm->pd.y = (j + 1) * K_SPACE;
			//tm.rgb = tf->tfe[(i * tf->x) + j].rgb;
			tm->rgb = WHITE;
			draw_line(tm);
			j++;
		}
		i++;
	}
}

t_fdf		*alloc_map(int x, int y)
{
	t_fdf		*tf;

	PROTECT((tf = ft_memalloc(sizeof(t_fdf))), NULL);
	PROTECT((tf->tfe = ft_memalloc(sizeof(t_fdf_elem) * x * y)), NULL);
	tf->x = x;
	tf->y = y;
	return (tf);
}

int		main(int argc, char **argv)
{
	t_mlx			tm;
	t_fdf			*tf;
	int i,j;

	tm.mlx_ptr = mlx_init();
	tm.win_ptr = mlx_new_window(tm.mlx_ptr, 1000, 1000, "Window Test 03");
	tm.img_ptr = mlx_new_image(tm.mlx_ptr, 300, 300);
	tm.img_data = mlx_get_data_addr(tm.img_ptr, &tm.bpp, &tm.szl, &tm.endian);
	tm.middle = (300*300*tm.bpp/8/4);
	ft_putnbr(tm.middle);
	fprintf(stdout, "bpp=%d, szl=%d, endian=%d\n", tm.bpp, tm.szl, tm.endian);

	PROTECT((tf = alloc_map(10, 10)), -1);



	draw_h(&tm, tf);
	draw_v(&tm, tf);

	mlx_put_image_to_window(tm.mlx_ptr, tm.win_ptr,tm.img_ptr, 100, 100);

	mlx_key_hook(tm.win_ptr, key_hook, &tm);
	mlx_mouse_hook(tm.win_ptr, mouse_hook, &tm);
	mlx_expose_hook(tm.win_ptr, expose_hook, &tm);
	mlx_loop_hook(tm.mlx_ptr, loop_hook, &tm);
	mlx_loop(tm.mlx_ptr);


	return (0);
}
