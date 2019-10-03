/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 17:41:13 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/03 14:20:59 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

void	init_a(t_env *env)
{
	env->posx = (int)env->width / 2;
	env->posy = (int)env->height / 2;
	env->dirx = -1.0;
	env->diry = 0.0;
	env->planex = 0.0;
	env->planey = 0.66;
	env->time = 0;
	env->oldtime = 0;
}

void	texture(t_env *env, int texnb)
{
	env->texnum = 0;
	if (env->side == 0)
		env->wallx = env->posy + env->perpwalldist * env->raydiry;
	else
		env->wallx = env->posx + env->perpwalldist * env->raydirx;
	env->wallx -= floor(env->wallx);
	env->t_x = (int)(env->wallx * (double)env->tex[texnb].width);
	if (env->side == 0 && env->raydirx > 0)
		env->t_x = env->tex[texnb].width - env->t_x - 1;
	if (env->side == 1 && env->raydiry < 0)
		env->t_x = env->tex[texnb].width - env->t_x - 1;
}

void	sole(t_env *env)
{
	int i;
	int j;

	i = -1;
	while (++i < HEIGHT && (j = -1))
		while (++j < WIDTH)
			env->my_str_img[i * WIDTH + j] = i < HEIGHT * .5 ? 0x3498DB :
		0x909497;
}

void	generate_tex_p(t_env *env)
{
	env->tex[0].img = mlx_xpm_file_to_image(env->mlx_ptr, "./texture/tex1.xpm",
		&env->tex[0].width, &env->tex[0].heigthwrhm);
	env->tex[1].img = mlx_xpm_file_to_image(env->mlx_ptr, "./texture/tex2.xpm",
		&env->tex[1].width, &env->tex[1].heigthwrhm);
	env->tex[2].img = mlx_xpm_file_to_image(env->mlx_ptr, "./texture/tex3.xpm",
		&env->tex[2].width, &env->tex[2].heigthwrhm);
	env->tex[3].img = mlx_xpm_file_to_image(env->mlx_ptr, "./texture/tex4.xpm",
		&env->tex[3].width, &env->tex[3].heigthwrhm);
	env->tex[0].adr = (unsigned int *)mlx_get_data_addr(env->tex[0].img,
		&(env->tex[0].bpp), &(env->tex[0].s_l), &(env->tex[0].endian));
	env->tex[1].adr = (unsigned int *)mlx_get_data_addr(env->tex[1].img,
		&(env->tex[1].bpp), &(env->tex[1].s_l), &(env->tex[1].endian));
	env->tex[2].adr = (unsigned int *)mlx_get_data_addr(env->tex[2].img,
		&(env->tex[2].bpp), &(env->tex[2].s_l), &(env->tex[2].endian));
	env->tex[3].adr = (unsigned int *)mlx_get_data_addr(env->tex[3].img,
		&(env->tex[3].bpp), &(env->tex[3].s_l), &(env->tex[3].endian));
}

void	generate_tex(t_env *env)
{
	env->tex[0].img = mlx_xpm_file_to_image(env->mlx_ptr, "./texture/mur.xpm",
		&env->tex[0].width, &env->tex[0].heigthwrhm);
	env->tex[1].img = mlx_xpm_file_to_image(env->mlx_ptr, "./texture/mur2.xpm",
		&env->tex[1].width, &env->tex[1].heigthwrhm);
	env->tex[2].img = mlx_xpm_file_to_image(env->mlx_ptr, "./texture/mur3.xpm",
		&env->tex[2].width, &env->tex[2].heigthwrhm);
	env->tex[3].img = mlx_xpm_file_to_image(env->mlx_ptr, "./texture/mur5.xpm",
		&env->tex[3].width, &env->tex[3].heigthwrhm);
	env->tex[0].adr = (unsigned int *)mlx_get_data_addr(env->tex[0].img,
		&(env->tex[0].bpp), &(env->tex[0].s_l), &(env->tex[0].endian));
	env->tex[1].adr = (unsigned int *)mlx_get_data_addr(env->tex[1].img,
		&(env->tex[1].bpp), &(env->tex[1].s_l), &(env->tex[1].endian));
	env->tex[2].adr = (unsigned int *)mlx_get_data_addr(env->tex[2].img,
		&(env->tex[2].bpp), &(env->tex[2].s_l), &(env->tex[2].endian));
	env->tex[3].adr = (unsigned int *)mlx_get_data_addr(env->tex[3].img,
		&(env->tex[3].bpp), &(env->tex[3].s_l), &(env->tex[3].endian));
}
