/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_newton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:35:49 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 23:08:56 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	newton_iteration(t_complex z)
{
	t_complex	ret;
	t_complex	trois;
	t_complex	t;

	trois.re = 3;
	trois.im = 0;
	t.re = cpx_pow(z, 3).re - 1;
	t.im = cpx_pow(z, 3).im;
	t = cpx_div(t, cpx_mult(trois, cpx_pow(z, 2)));
	ret.re = z.re - t.re;
	ret.im = z.im - t.im;
	return (ret);
}

double	distance(t_complex z1, t_complex z2)
{
	t_complex	s;

	s.re = z1.re - z2.re;
	s.im = z1.im - z2.im;
	return (module(s));
}

int	newton_recursive(t_complex z, int nb_it, t_roots r)
{
	if (nb_it <= 0)
	{
		if (distance(z, r.r1) < distance(z, r.r2) && distance(z,
				r.r1) < distance(z, r.r3))
			return (1);
		else if (distance(z, r.r2) < distance(z, r.r1) && distance(z,
				r.r2) < distance(z, r.r3))
			return (2);
		else
			return (3);
	}
	return (newton_recursive(newton_iteration(z), nb_it - 1, r));
}

void	draw_newton(t_env *e)
{
	int			x;
	int			y;
	t_complex	z0;
	int			ret;

	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			z0.re = x * e->pixel_size + e->re_min;
			z0.im = y * e->pixel_size + e->im_min;
			ret = newton_recursive(z0, e->nb_it, e->newton_roots);
			if (ret)
				putpixel(x, y, e, ret);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int	palette_newton(int ret, t_env *e)
{
	(void)e;
	if (ret == 1)
		return (0x00ff0000);
	if (ret == 2)
		return (0x0000ff00);
	if (ret == 3)
		return (0x000000ff);
	else
		return (0);
}
