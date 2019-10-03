/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_draw.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/18 15:27:43 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/03 14:21:39 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

void		drow_loop(t_env *env, int i, int x)
{
	uint32_t	color;
	int			tmp;

	color = 0x000000;
	while (env->drawstart < env->drawend)
	{
		tmp = env->drawstart * 256 - HEIGHT * 128 + env->lineheight * 128;
		env->t_y = ((tmp * env->tex[i].heigthwrhm) / env->lineheight) / 256;
		color = get_color(env->tex[i], env->t_x, env->t_y);
		color = (color >> 1) & 8355711;
		env->my_str_img[env->drawstart * WIDTH + x] = color;
		env->drawstart++;
	}
}

void		draw_tex(t_env *env, int x)
{
	int i;

	i = 0;
	if (env->side == 1)
	{
		if (env->stepy == 1)
			i = 0;
		else if (env->stepy == -1)
			i = 1;
	}
	else if (env->side == 0)
	{
		if (env->stepx == 1)
			i = 2;
		else if (env->stepx == -1)
			i = 3;
	}
	texture(env, i);
	drow_loop(env, i, x);
}

void		draw_wall(t_env *env, int x)
{
	unsigned int color;

	color = 0;
	if (env->side == 1)
	{
		if (env->stepy == 1)
			color = wall_color(255, 0, 255);
		else if (env->stepy == -1)
			color = wall_color(0, 0, 255);
	}
	else if (env->side == 0)
	{
		if (env->stepx == 1)
			color = wall_color(0, 255, 0);
		else if (env->stepx == -1)
			color = wall_color(255, 255, 0);
	}
	else if (env->map[env->mapx][env->mapy] == 4)
		color = wall_color(0, 0, 0);
	while (env->drawstart <= env->drawend)
	{
		color_pixel(env, x, env->drawstart, color);
		env->drawstart++;
	}
}
