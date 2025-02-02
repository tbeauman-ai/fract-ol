/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:14:55 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 23:12:56 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_env *e)
{
	int			x;
	int			y;
	t_complex	z0;
	int			i;

	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			z0.re = x * e->pixel_size + e->re_min;
			z0.im = y * e->pixel_size + e->im_min;
			i = is_escapingjul(z0, e->jul, e->nb_it, e);
			if (i < e->nb_it && i > 0)
				putpixel(x, y, e, i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	draw_mandelbrot(t_env *e)
{
	int			x;
	int			y;
	t_complex	c;
	int			i;
	t_complex	z0;

	z0.re = 0;
	z0.im = 0;
	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			c.re = x * e->pixel_size + e->re_min;
			c.im = y * e->pixel_size + e->im_min;
			i = is_escaping(z0, c, e->nb_it, e);
			if (i < e->nb_it && i)
				putpixel(x, y, e, i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	draw_burning_ship(t_env *e)
{
	int			x;
	int			y;
	t_complex	c;
	int			i;
	t_complex	z0;

	z0.re = 0;
	z0.im = 0;
	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			c.re = x * e->pixel_size + e->re_min;
			c.im = y * e->pixel_size + e->im_min;
			i = is_escaping_burning_ship(z0, c, e->nb_it, e);
			if (i)
				putpixel(x, y, e, i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	draw_tricorn(t_env *e)
{
	int			x;
	int			y;
	t_complex	c;
	int			i;
	t_complex	z0;

	z0.re = 0;
	z0.im = 0;
	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			c.re = x * e->pixel_size + e->re_min;
			c.im = y * e->pixel_size + e->im_min;
			i = is_escaping_tricorn(z0, c, e->nb_it, e);
			if (i)
				putpixel(x, y, e, i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	draw_burning_julia(t_env *e)
{
	int			x;
	int			y;
	t_complex	z0;
	int			i;

	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			z0.re = x * e->pixel_size + e->re_min;
			z0.im = y * e->pixel_size + e->im_min;
			i = is_escaping_burning_jul(z0, e->jul, e->nb_it, e);
			if (i < e->nb_it && i > 0)
				putpixel(x, y, e, i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
