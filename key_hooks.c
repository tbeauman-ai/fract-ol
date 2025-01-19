/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:55:29 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 18:49:12 by tbeauman         ###   ########.fr       */
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

void    reset_image(t_env *e)
{
    mlx_destroy_image(e->mlx, e->img);
    e->img = mlx_new_image(e->mlx, 600, 400);
    e->img_address = mlx_get_data_addr(e->img, &e->bits_per_pixel, &e->line_length, &e->endian);
}


void    move_image(int kc, t_env *e)
{
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
}
void    toggle(int  *fix)
{
    if (*fix)
        *fix = 0;
    else
        *fix = 1;
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
    if (kc == KEY_ESC && clear_mlx(e))
        exit (1); // /!\ LEAKS
    if (kc == KEY_P)
        e->puissance += 1;
    if (kc == KEY_O)
        e->puissance -= 1;
    if (kc == KEY_F)
        toggle(&e->fix_julia);
    if (kc == KEY_PLUS)
        e->nb_it += 5;
    if (kc == KEY_MOINS)
        e->nb_it -= 5;
    move_image(kc, e);
    reset_image(e);
    mlx_clear_window(e->mlx, e->win);
    e->draw_fract(e);
    return (1);
}