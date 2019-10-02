/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 17:41:13 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 17:41:14 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

void init_a(t_env *env)
{  
    env->posX = 10;
    env->posY = 10;
    env->dirX = -1.0;
    env->dirY = 0.0;
    env->planeX = 0.0;
    env->planeY = 0.66;
    env->time = 0;
    env->oldtime = 0;
}

void generate_tex(t_env *env)
{
    env->tex[0].img = mlx_xpm_file_to_image(env->mlx_ptr, "./texture/mur.xpm", &env->tex[0].width, &env->tex[0].heigthwrhm);
    env->tex[1].img = mlx_xpm_file_to_image(env->mlx_ptr, "./texture/mur.xpm", &env->tex[1].width, &env->tex[1].heigthwrhm);
    env->tex[2].img = mlx_xpm_file_to_image(env->mlx_ptr, "./texture/mur.xpm", &env->tex[2].width, &env->tex[2].heigthwrhm);
    env->tex[3].img = mlx_xpm_file_to_image(env->mlx_ptr, "./texture/mur.xpm", &env->tex[3].width, &env->tex[3].heigthwrhm);
    env->tex[0].adr = (unsigned int *) mlx_get_data_addr(env->tex[0].img, &(env->tex[0].bpp), &(env->tex[0].s_l), &(env->tex[0].endian));
    env->tex[1].adr = (unsigned int *) mlx_get_data_addr(env->tex[1].img, &(env->tex[1].bpp), &(env->tex[1].s_l), &(env->tex[1].endian));
    env->tex[2].adr = (unsigned int *) mlx_get_data_addr(env->tex[2].img, &(env->tex[2].bpp), &(env->tex[2].s_l), &(env->tex[2].endian));
    env->tex[3].adr = (unsigned int *) mlx_get_data_addr(env->tex[3].img, &(env->tex[3].bpp), &(env->tex[3].s_l), &(env->tex[3].endian));
}

void init_tex(t_env *env)
{
    env->posX = 22.0;
    env->posY = 11.5;
    env->dirX = -1.0;
    env->dirY = 0;
    env->planeX = 0;
    env->planeY = 0.66;
    env->time = 0;
    env->oldtime = 0;
}
