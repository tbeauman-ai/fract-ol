/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:12 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/18 18:17:02 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "typedefs.h"
# include <math.h>
# include "keys.h"

double  module(t_complex z);
t_complex   cpx_mult(t_complex a, t_complex b);
t_complex   cpx_div(t_complex a, t_complex b);
t_complex   cpx_inv(t_complex a);

void    putpixel(int x, int y, t_env *e, int i);
void    draw_mandelbrot(t_env *e);

int     is_escaping(t_complex z, t_complex c, int nb_it, t_env *e);
t_complex   mandelbrot_rec(t_complex z, t_complex c, t_env *e);

int		palette_1(int index, t_env *e);
int		palette_2(int index, t_env *e);
int		palette_3(int index, t_env *e);
int		palette_4(int index, t_env *e);
int     key_pressed(int kc, t_env *e);
int		motion_hook(int x, int y, t_env *e);
void	clear_image(char **address);
int     mouse_hook(int bt, int x, int y, t_env *e);
void    draw_mandelbrot(t_env *e);

#endif