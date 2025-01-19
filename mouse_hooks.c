/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:56:46 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 22:46:02 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_in(int x, int y, t_env *e)
{
	double	re_mouse;
	double	im_mouse;
	double	range_re;
	double	range_im;

	range_re = e->re_max - e->re_min;
	range_im = e->im_max - e->im_min;
	re_mouse = e->re_min + x * range_re / 600;
	im_mouse = e->im_min + y * range_im / 400;
	range_re /= 1.25;
	range_im /= 1.25;
	e->re_min = re_mouse - (re_mouse - e->re_min) / 1.25;
	e->re_max = e->re_min + range_re;
	e->im_min = im_mouse - (im_mouse - e->im_min) / 1.25;
	e->im_max = e->im_min + range_im;
	e->pixel_size /= 1.25;
	e->nb_it += 2;
}

static void	zoom_out(int x, int y, t_env *e)
{
	double	re_mouse;
	double	im_mouse;
	double	range_re;
	double	range_im;

	range_re = e->re_max - e->re_min;
	range_im = e->im_max - e->im_min;
	re_mouse = e->re_min + x * range_re / 600;
	im_mouse = e->im_min + y * range_im / 400;
	range_re *= 1.25;
	range_im *= 1.25;
	e->re_min = re_mouse - (re_mouse - e->re_min) * 1.25;
	e->re_max = e->re_min + range_re;
	e->im_min = im_mouse - (im_mouse - e->im_min) * 1.25;
	e->im_max = e->im_min + range_im;
	e->pixel_size *= 1.25;
	e->nb_it -= 2;
}

int	mouse_roll(int bt, int x, int y, t_env *e)
{
	if (e->ens == 0)
		return (0);
	if (bt == SCROLL_DOWN || bt == SCROLL_UP)
	{
		reset_image(e);
		if (bt == SCROLL_DOWN)
			zoom_out(x, y, e);
		if (bt == SCROLL_UP)
			zoom_in(x, y, e);
		mlx_clear_window(e->mlx, e->win);
		e->draw_fract(e);
	}
	return (1);
}

int	motion_hook(int x, int y, t_env *e)
{
	if ((e->ens == 'j' || e->ens == 'i') && e->fix_julia == 0)
	{
		reset_image(e);
		e->jul.re = e->re_min + x * (e->re_max - e->re_min) / 600;
		e->jul.im = e->im_min + y * (e->im_max - e->im_min) / 400;
		mlx_clear_window(e->mlx, e->win);
		e->draw_fract(e);
	}
	return (1);
}
