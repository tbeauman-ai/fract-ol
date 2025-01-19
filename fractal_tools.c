/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:14:06 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 19:00:23 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     is_escaping(t_complex z, t_complex c, int nb_it, t_env *e)
{
    if (module(z) > 2 || nb_it <= 0)
        return (e->nb_it - nb_it);
    z = mandelbrot_rec(z, c, e);
    return (is_escaping(z, c, nb_it - 1, e));
}

int     is_escapingjul(t_complex z, t_complex c, int nb_it, t_env *e)
{
    if (module(z) > 2 || nb_it <= 0)
        return (nb_it);
    z = mandelbrot_rec(z, c, e);
    return (is_escapingjul(z, c, nb_it - 1, e));
}

int     is_escaping_burning_ship(t_complex z, t_complex c, int nb_it, t_env *e)
{
    if (module(z) > 2 || nb_it <= 0)
        return (nb_it);
    z = burning_ship_rec(z, c, e);
    return (is_escaping_burning_ship(z, c, nb_it - 1, e));
}

int     is_escaping_tricorn(t_complex z, t_complex c, int nb_it, t_env *e)
{
    if (module(z) > 2 || nb_it <= 0)
        return (nb_it);
    z = tricorn_rec(z, c, e);
    return (is_escaping_tricorn(z, c, nb_it - 1, e));
}
