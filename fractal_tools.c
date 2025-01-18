/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:14:06 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/18 18:16:04 by tbeauman         ###   ########.fr       */
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

t_complex   mandelbrot_rec(t_complex z, t_complex c, t_env *e)
{
    t_complex   ret;
    t_complex   z_2;
    int         i;

    i = 1;
    z_2 = z;
    while (i++ < abs(e->puissance))
        z_2 = cpx_mult(z, z_2);
    if (e->puissance < 0)
        z_2 = cpx_inv(z_2);
    if (e->puissance == 0)
    {
        z_2.re = 1;
        z_2.im = 0;
    }
    ret.re = z_2.re + c.re;
    ret.im = z_2.im + c.im;
    return (ret);
}
