#include "render.h"

static void	bres_define(t_bres *b, t_point *init, t_point *dest)
{
	b->dx = abs(dest->x - init->x);
	b->dy = abs(dest->y - init->y);
	b->p = b->dx - b->dy;
	b->x = init->x;
	b->y = init->y;
	b->sign_x = 1;
	b->sign_y = 1;
	if (init->x > dest->x)
		b->sign_x = -1;
	if (init->y > dest->y)
		b->sign_y = -1;
}

void	bresenham(t_image *img, t_point init, t_point dest)
{
	t_bres	bres;
	int		p;

	bres_define(&bres, &init, &dest);
	while (bres.x != dest.x || bres.y != dest.y)
	{
		bres.color = 0xFA8218;
		put_pixel_img(img, bres.x, bres.y, bres.color);
		p = bres.p;
		if (p * 2 > -bres.dy)
		{
			bres.p -= bres.dy;
			bres.x += bres.sign_x;
		}
		if (p * 2 < bres.dx)
		{
			bres.p += bres.dx;
			bres.y += bres.sign_y;
		}
	}
}