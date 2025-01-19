/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:12 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 20:15:29 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "typedefs.h"
# include <math.h>
# include "keys.h"

int     clear_mlx(t_env *e);
void    reset_image(t_env *e);
void    init(t_env *e, char ens);
void	display_menu(t_env *e);

double  module(t_complex z);
t_complex   cpx_mult(t_complex a, t_complex b);
t_complex   cpx_div(t_complex a, t_complex b);
t_complex   cpx_inv(t_complex a);
t_complex   cpx_pow(t_complex a, int n);

void    putpixel(int x, int y, t_env *e, int i);
void    draw_mandelbrot(t_env *e);
void    draw_julia(t_env *e);
void    draw_burning_ship(t_env *e);
void    draw_tricorn(t_env *e);
void	draw_newton(t_env *e);
void	draw_burning_julia(t_env *e);

int     is_escaping(t_complex z, t_complex c, int nb_it, t_env *e);
int     is_escapingjul(t_complex z, t_complex c, int nb_it, t_env *e);
int     is_escaping_burning_ship(t_complex z, t_complex c, int nb_it, t_env *e);
int     is_escaping_tricorn(t_complex z, t_complex c, int nb_it, t_env *e);
int     is_escaping_burning_jul(t_complex z, t_complex c, int nb_it, t_env *e);

t_complex   mandelbrot_rec(t_complex z, t_complex c, t_env *e);
t_complex   burning_ship_rec(t_complex z, t_complex c, t_env *e);
t_complex   tricorn_rec(t_complex z, t_complex c, t_env *e);

int		palette_1(int index, t_env *e);
int		palette_2(int index, t_env *e);
int		palette_3(int index, t_env *e);
int		palette_4(int index, t_env *e);
int		palette_newton(int ret, t_env *e);
int     key_pressed(int kc, t_env *e);
int		motion_hook(int x, int y, t_env *e);
void	clear_image(char **address);
int     mouse_roll(int bt, int x, int y, t_env *e);

#endif