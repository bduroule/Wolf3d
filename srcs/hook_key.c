/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf_hook.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/23 16:52:58 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/03 14:22:06 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

void	straff(int key, t_env *e)
{
	if (e->space == 0 ? key == 0 : key == 12)
	{
		if (!(e->map[(int)((e->posx + (e->planex > 0 ? -.05 : +.05)) - e->planex *
		e->movespeed)][(int)(e->posy)] == 1))
			e->posx -= e->planex * e->movespeed;
		if (!(e->map[(int)(e->posx)][(int)((e->posy + (e->planey > 0 ? -.05 :
		+.05)) - e->planey * e->movespeed)] == 1))
			e->posy -= e->planey * e->movespeed;
	}
	if (e->space == 0 ? key == 2 : key == 14)
	{
		if (!(e->map[(int)((e->posx - (e->planex > 0 ? -.07 : +.07)) + e->planex
		* e->movespeed)][(int)(e->posy)] == 1))
			e->posx += e->planex * e->movespeed;
		if (!(e->map[(int)(e->posx)][(int)((e->posy - (e->planey > 0 ? -.07 :
		+.07)) + e->planey * e->movespeed)] == 1))
			e->posy += e->planey * e->movespeed;
	}
}

int		deal_key2(int key, t_env *e)
{
	if (e->space == 0)
		return (0);
	if (key == 0)
	{
		e->olddirx = e->dirx;
		e->dirx = e->dirx * cos(e->rotspeed) - e->diry * sin(e->rotspeed);
		e->diry = e->olddirx * sin(e->rotspeed) + e->diry * cos(e->rotspeed);
		e->oldplanex = e->planex;
		e->planex = e->planex * cos(e->rotspeed) - e->planey *
		sin(e->rotspeed);
		e->planey = e->oldplanex * sin(e->rotspeed) + e->planey *
		cos(e->rotspeed);
	}
	if (key == 2)
	{
		e->olddirx = e->dirx;
		e->oldplanex = e->planex;
		e->dirx = e->dirx * cos(-e->rotspeed) - e->diry * sin(-e->rotspeed);
		e->diry = e->olddirx * sin(-e->rotspeed) + e->diry * cos(-e->rotspeed);
		e->planex = e->planex * cos(-e->rotspeed) - e->planey *
		sin(-e->rotspeed);
		e->planey = e->oldplanex * sin(-e->rotspeed) + e->planey *
		cos(-e->rotspeed);
	}
	return (0);
}

void		deal_key1(int key, t_env *e)
{
	e->movespeed = e->speed_id * 5.0;
	e->rotspeed = e->speed_id * 3.0;
	if (key == 1)
	{
		if (!(e->map[(int)((e->posx + (e->dirx > 0 ? -.07 : +.07)) - e->dirx *
			e->movespeed)][(int)e->posy] == 1))
			e->posx -= e->dirx * e->movespeed;
		if (!(e->map[(int)e->posx][(int)((e->posy + (e->diry > 0 ? -.07 :
		+.07)) - e->diry * e->movespeed)] == 1))
			e->posy -= e->diry * e->movespeed;
	}
	if (key == 13)
	{
		if (!(e->map[(int)((e->posx - (e->dirx > 0 ? -.07 : +.07)) + e->dirx
			* e->movespeed)][(int)(e->posy)] == 1))
			e->posx += e->dirx * e->movespeed;
		if (!(e->map[(int)(e->posx)][(int)((e->posy - (e->diry > 0 ? -.07 :
		+.07)) + e->diry * e->movespeed)] == 1))
			e->posy += e->diry * e->movespeed;
	}
	if (key == 53)
		exit(EXIT_SUCCESS);
		straff(key, e);
}

int	deal_key(int key, t_env *e)
{
	if (key == 49 && e->space == 1)
		e->space = 0;
	else if (key == 49 && e->space == 0)
		e->space = 1;
	if (key == 17)
		e->ttx = 1;
	if (key == 16)
		e->ttx = 2;
	if (key == 32)
		e->ttx = 0;
	if (key == 69 && e->speed_id < 0.1)
		e->speed_id += 0.01;
	if (key == 78 && e->speed_id > 0.01)
		e->speed_id -= 0.01;
	printf("%f\n", e->speed_id);
	deal_key1(key, e);
	deal_key2(key, e);
	display(e);
	return (0);
}

void	hook_loop(t_env *e)
{
	mlx_hook(e->win_ptr, 17, 0, out, e);
	mlx_hook(e->win_ptr, 2, 0, deal_key, e);
	mlx_hook(e->win_ptr, 6, 0, mouse_moove, e);
}
