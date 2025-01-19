/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:56:46 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 18:49:37 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    zoom_out(int x, int y, t_env *e)
{
    double  re_m;
    double  im_m;
    double  old[4];

    old[0] = e->re_min;
    old[1] = e->re_max;
    old[2] = e->im_min;
    old[3] = e->im_max;
    re_m = e->re_min + x * (e->re_max - e->re_min) / 600;
    im_m = e->im_min + y * (e->im_max - e->im_min) / 400;
    e->pixel_size *= 1.25;
    e->nb_it -= 2;
    e->re_min = re_m - (old[1] - old[0]) * (1.25 / 2); 
    e->re_max = re_m + (old[1] - old[0]) * (1.25 / 2); 
    e->im_min = im_m - (old[3] - old[2]) * (1.25 / 2); 
    e->im_max = im_m + (old[3] - old[2]) * (1.25 / 2); 
}

void    zoom_in(int x, int y, t_env *e)
{
    double  re_m;
    double  im_m;
    double  old[4];

    old[0] = e->re_min;
    old[1] = e->re_max;
    old[2] = e->im_min;
    old[3] = e->im_max;
    re_m = e->re_min + x * (e->re_max - e->re_min) / 600;
    im_m = e->im_min + y * (e->im_max - e->im_min) / 400;
    e->pixel_size /= 1.25;
    e->nb_it += 2;
    e->re_min = re_m - (old[1] - old[0]) / 2.5; 
    e->re_max = re_m + (old[1] - old[0]) / 2.5; 
    e->im_min = im_m - (old[3] - old[2]) / 2.5; 
    e->im_max = im_m + (old[3] - old[2]) / 2.5; 
}

void    zoom_in2(int x, int y, t_env *e)
{
    double  re_mouse;
    double  im_mouse;
    double  range_re;
    double  range_im;

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

void    zoom_out2(int x, int y, t_env *e)
{
    double  re_mouse;
    double  im_mouse;
    double  range_re;
    double  range_im;

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

int     mouse_roll(int bt, int x, int y, t_env *e)
{
    if (e->ens == 0)
        return (0);
    if (bt == SCROLL_DOWN || bt == SCROLL_UP)
    {
        // clear_image(&e->img_address);
        reset_image(e);
        if (bt == SCROLL_DOWN)
            zoom_out2(x, y, e);
        if (bt == SCROLL_UP)
            zoom_in2(x, y, e);
        mlx_clear_window(e->mlx, e->win);
        e->draw_fract(e);
    }
    return (1);
}

int		motion_hook(int x, int y, t_env *e)
{
	if (e->ens == 'j' && e->fix_julia == 0)
	{
        reset_image(e);
		e->jul.re = e->re_min + x * (e->re_max - e->re_min) / 600;
		e->jul.im = e->im_min + y * (e->im_max - e->im_min) / 400;
		mlx_clear_window(e->mlx, e->win);
		e->draw_fract(e);
	}
	return (1);
}
