/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:44 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/14 15:17:20 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct  s_complex
{
    double      re;
    double      im;
}               t_complex;

typedef struct  s_env
{
    void        *mlx;
    void        *win;
    void        *img;
    char        *img_address;
    double      re_min;
    double      re_max;
    double      im_min;
    double      im_max;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    char        ens;
    int         nb_it;
    double      pixel_size;
    int         puissance;
}               t_env;


#endif