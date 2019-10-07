/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_hook2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:01:57 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 14:01:59 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

int		mouse_m(int x, t_env *e)
{
	if (x > e->tmpx)
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
	e->tmpx = x;
	display(e);
	return (0);
}

int		mouse_moove(int x, int y, t_env *e)
{
	if (!((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT) && e->space == 0))
		return (0);
	if (x < e->tmpx)
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
	mouse_m(x, e);
	return (0);
}
