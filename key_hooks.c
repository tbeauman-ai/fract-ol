/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:55:29 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 23:03:39 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_image_left_and_right(int kc, t_env *e)
{
	if (kc == KEY_LEFT || kc == KEY_RIGHT)
	{
		if (kc == KEY_RIGHT)
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
}

static void	move_image_up_and_down(int kc, t_env *e)
{
	if (kc == KEY_UP || kc == KEY_DOWN)
	{
		if (kc == KEY_DOWN)
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

static void	change_colors_power_or_fix(int kc, t_env *e)
{
	if (kc == KEY_1)
		e->palette = &palette_1;
	if (kc == KEY_2)
		e->palette = &palette_2;
	if (kc == KEY_3)
		e->palette = &palette_3;
	if (kc == KEY_4)
		e->palette = &palette_4;
	if (kc == KEY_P)
		e->puissance += 1;
	if (kc == KEY_O)
		e->puissance -= 1;
	if (kc == KEY_F)
	{
		if (e->fix_julia)
			e->fix_julia = 0;
		else
			e->fix_julia = 1;
	}
}

static void	change_ensemble_or_iterations(int kc, t_env *e)
{
	if (kc == KEY_J)
		init(e, 'j');
	if (kc == KEY_M)
		init(e, 'm');
	if (kc == KEY_N)
		init(e, 'n');
	if (kc == KEY_B)
		init(e, 'b');
	if (kc == KEY_I)
		init(e, 'i');
	if (kc == KEY_T)
		init(e, 't');
	if (kc == KEY_TAB)
		e->ens = 0;
	if (kc == KEY_PLUS)
		e->nb_it += 5;
	if (kc == KEY_MOINS)
		e->nb_it -= 5;
}

int	key_pressed(int kc, t_env *e)
{
	if (kc == KEY_ESC && clear_mlx(e))
		exit(1);
	change_colors_power_or_fix(kc, e);
	change_ensemble_or_iterations(kc, e);
	move_image_left_and_right(kc, e);
	move_image_up_and_down(kc, e);
	reset_image(e);
	mlx_clear_window(e->mlx, e->win);
	if (e->ens)
		e->draw_fract(e);
	else
		display_menu(e);
	return (1);
}
