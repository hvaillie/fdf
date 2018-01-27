#include <mlx.h>
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libft/includes/libft.h"


int 	key_hook(int key, void *param) {
	ft_putstr("Key=");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == ESCAPE_KEY)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	ft_putstr("Mouse Button=");
	ft_putnbr(button);
	ft_putstr(" ,x=");
	ft_putnbr(x);
	ft_putstr(" ,y=");
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}

int		expose_hook(void *param)
{
	ft_putstr("Expose");
	ft_putchar('\n');
	return (0);
}

int		loop_hook(void *param)
{
	return (0);
}

int 	draw_line(t_mlx *tm)
{
	int				diffx;
	int				diffy;
	float			incx;
	float			incy;
	unsigned int	color;
	unsigned char	octets[4];
	int				loops;
	int				i;
	int				j;
	int				x;
	int				y;

	diffx = tm->pd.x - tm->po.x;
	diffy = tm->pd.y - tm->po.y;
	loops = ft_max(ft_abs(diffx), ft_abs(diffy));
	incx = (float)diffx / loops;
	incy = (float)diffy / loops;
	color = mlx_get_color_value(tm->mlx_ptr, tm->rgb);
	octets[0] = color >> 0;
	octets[1] = color >> 8;
	octets[2] = color >> 16;
	octets[3] = color >> 24;

	fprintf(stdout, "loop=%d, incx=%f, incy=%f, color=(%d) %.2x %.2x %.2x %.2x\n",
			loops, incx, incy, color, octets[0], octets[1], octets[2], octets[3]);
	fprintf(stdout, "Orig=(%d,%d), Dest=(%d,%d)\n", tm->po.x, tm->po.y, tm->pd.x, tm->pd.y);
	i = 0;
	while (i <= loops)
	{
		x = tm->po.x + (incx * i);
		y = tm->po.y + (incy * i);
		//fprintf(stdout, "point %d=(%d,%d)\n", i, x, y);
		j = 0;
		while(j < tm->bpp / 8)
		{
			tm->img_data[(tm->szl * y) + (tm->bpp / 8 * x) + j] = octets[j];
			j++;
		}
		i++;
	}

	return (loops);
}

int main(int argc, char **argv)
{
	t_mlx			tm;

	tm.mlx_ptr = mlx_init();
	tm.win_ptr = mlx_new_window(tm.mlx_ptr, 400, 400, "Window Test 02");
	tm.img_ptr = mlx_new_image(tm.mlx_ptr, 100, 100);
	tm.img_data = mlx_get_data_addr(tm.img_ptr, &tm.bpp, &tm.szl, &tm.endian);
	fprintf(stdout, "bpp=%d, szl=%d, endian=%d\n", tm.bpp, tm.szl, tm.endian);

	int	i = 0;
	while (i < 80)
	{
		tm.po.x = 10;
		tm.po.y = 10 + i;
		tm.pd.x = 90;
		tm.pd.y = 90 - i;
		tm.rgb = WHITE - (i * 100000);
		draw_line(&tm);
		i = i + 2;
	}
	mlx_put_image_to_window(tm.mlx_ptr, tm.win_ptr,tm.img_ptr, 200, 200);
	mlx_key_hook(tm.win_ptr, key_hook, &tm);
	mlx_mouse_hook(tm.win_ptr, mouse_hook, &tm);
	mlx_expose_hook(tm.win_ptr, expose_hook, &tm);
	mlx_loop_hook(tm.mlx_ptr, loop_hook, &tm);
	mlx_loop(tm.mlx_ptr);


	return (0);
}
