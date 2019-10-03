/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/16 13:19:06 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/03 14:21:57 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

void		init_raycasting(t_env *env, int x)
{
	env->camerax = (2 * x) / (double)WIDTH - 1;
	env->raydirx = env->dirx + env->planex * env->camerax;
	env->raydiry = env->diry + env->planey * env->camerax;
	env->mapx = (int)env->posx;
	env->mapy = (int)env->posy;
	env->deltadistx = fabs(1 / env->raydirx);
	env->deltadisty = fabs(1 / env->raydiry);
	env->stepx = 0;
	env->stepy = 0;
	env->hit = 0;
	env->side = 0;
}

void		init_calc_raycasting(t_env *env)
{
	if (env->raydirx < 0)
	{
		env->stepx = -1;
		env->sidedistx = (env->posx - env->mapx) * env->deltadistx;
	}
	else
	{
		env->stepx = 1;
		env->sidedistx = (env->mapx + 1.0 - env->posx) * env->deltadistx;
	}
	if (env->raydiry < 0)
	{
		env->stepy = -1;
		env->sidedisty = (env->posy - env->mapy) * env->deltadisty;
	}
	else
	{
		env->stepy = 1;
		env->sidedisty = (env->mapy + 1.0 - env->posy) * env->deltadisty;
	}
}

void		raycasting_hit(t_env *env)
{
	while (env->hit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->deltadistx;
			env->mapx += env->stepx;
			env->side = 0;
		}
		else
		{
			env->sidedisty += env->deltadisty;
			env->mapy += env->stepy;
			env->side = 1;
		}
		if (env->map[env->mapx][env->mapy] > 0)
			env->hit = 1;
	}
}

void		raycasting_wall_distance(t_env *env, int x)
{
	if (env->side == 0)
		env->perpwalldist = (env->mapx - env->posx + (1 - env->stepx) / 2) /
		env->raydirx;
	else
		env->perpwalldist = (env->mapy - env->posy + (1 - env->stepy) / 2) /
		env->raydiry;
	env->lineheight = (int)(HEIGHT / env->perpwalldist);
	env->drawstart = -env->lineheight / 2 + HEIGHT / 2;
	if (env->drawstart < 0)
		env->drawstart = 0;
	env->drawend = env->lineheight / 2 + HEIGHT / 2;
	if (env->drawend >= HEIGHT)
		env->drawend = HEIGHT - 1;
	if (env->ttx == 0)
		draw_wall(env, x);
	if (env->ttx == 1)
		draw_tex(env, x);
}
