/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 17:39:24 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/03 14:21:11 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

unsigned int	wall_color(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

unsigned int	get_color(t_texture tex, int x, int y)
{
	if (!((x >= 0 && x < tex.width) && (y >= 0 && y < tex.heigthwrhm)))
		return (0x000000);
	return (tex.adr[y * tex.width + x]);
}

void			color_pixel(t_env *env, int x, int y, unsigned int color)
{
	int i;

	if (!((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT)))
		return ;
	i = (x * 4) + (y * env->s_l);
	env->my_str_img[env->drawstart * WIDTH + x] = color;
}

void			display(t_env *env)
{
	int i;
	int j;

	i = -1;
	if (env->ttx == 1)
		if (!(generate_tex(env)))
		{
			env->ttx = 0;
		}
	if (env->ttx == 2)
		if (!(generate_tex_p(env)))
		{
			env->ttx = 0;
		}
	while (++i < WIDTH && (j = -1))
		while (++j < HEIGHT)
			env->my_str_img[j * WIDTH + i] = 0x000000;
	wolf_run(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->ptr_img, 0, 0);
}
