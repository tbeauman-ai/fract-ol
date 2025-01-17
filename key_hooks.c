/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:55:29 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/16 13:13:37 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	clear_image(char **address)
{
	int		i;

	i = 0;
	while (i < 600 * 400 * 4)
		(*address)[i++] = 0;
}

int		motion_hook(int x, int y, t_env *e)
{
    (void)x;
    (void)e;
    (void)y;
	return (1);
}

int     key_pressed(int kc, t_env *e)
{
    if (kc == KEY_1)
        e->palette = &palette_1;
    if (kc == KEY_2)
        e->palette = &palette_2;
    if (kc == KEY_3)
        e->palette = &palette_3;
    if (kc == KEY_4)
        e->palette = &palette_4;
    if (kc == KEY_ESC)
        exit (1); // /!\ LEAKS
    if (kc == KEY_P)
        e->puissance += 1;
    if (kc == KEY_O)
        e->puissance -= 1;
    if (kc == KEY_PLUS)
        e->nb_it += 5;
    if (kc == KEY_MOINS)
        e->nb_it -= 5;
    if (kc == KEY_LEFT || kc == KEY_RIGHT)
    {
        if (kc == KEY_LEFT)
        {
            e->re_min += e->pixel_size * 50;
            e->re_max += e->pixel_size * 50;
        }
        else
        {
            e->re_min -= e->pixel_size * 50;
            e->re_max -= e->pixel_size * 50;
        }
    }
    if (kc == KEY_UP || kc == KEY_DOWN)
    {
        if (kc == KEY_UP)
        {
            e->im_min += e->pixel_size * 50;
            e->im_max += e->pixel_size * 50;
        }
        else
        {
            e->im_min -= e->pixel_size * 50;
            e->im_max -= e->pixel_size * 50;
        }
    }
    clear_image(&e->img_address);
    mlx_clear_window(e->mlx, e->win);
    draw_mandelbrot(e);
    return (1);
}