/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:44 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/21 18:14:26 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct  s_complex
{
    double      re;
    double      im;
}               t_complex;

typedef struct		s_roots
{
	t_complex			r1;
	t_complex			r2;
	t_complex			r3;
}					t_roots;

typedef struct  s_env
{
    void        *mlx;
    void        *win;
    void        *img;
    char        *img_address;
    int         bpp;
    int         sline;
    int         endian;
    double      pixel_size;
    double      re_min;
    double      re_max;
    double      im_min;
    double      im_max;
    char        ens;
    int         nb_it;
    int         puissance;
    t_complex   jul;
    t_roots     newton_roots;
    int         fix_julia;
    void        (*draw_fract)(struct s_env *);
	int			(*palette)(int, struct s_env*);
}               t_env;


#endif