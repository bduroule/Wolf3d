/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf_hook.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/23 16:52:58 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/23 16:53:02 by jadonvez    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

int		out(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
	return (0);
}

int		deal_key(int key, t_env *env)
{
    env->moveSpeed = 0.02 * 5.0;
    env->rotSpeed = 0.03 * 3.0;
    if (key == 0)
    {
        env->oldDirX = env->dirX;
        env->dirX = env->dirX * cos(env->rotSpeed) - env->dirY * sin(env->rotSpeed);
        env->dirY = env->oldDirX * sin(env->rotSpeed) + env->dirY * cos(env->rotSpeed);
        env->planeX = env->planeX * cos(env->rotSpeed) - env->planeY * sin(env->rotSpeed);
        env->planeY = env->oldPlaneX * sin(env->rotSpeed) + env->planeY * cos(env->rotSpeed);
    }
    if (key == 1)
        {
            env->posX -= env->dirX * env->moveSpeed;
            env->posY -= env->dirY * env->moveSpeed;
        }
    if (key == 2)
    {
        env->oldDirX = env->dirX;
        env->dirX = env->dirX * cos(-env->rotSpeed) - env->dirY * sin(-env->rotSpeed);
        env->dirY = env->oldDirX * sin(-env->rotSpeed) + env->dirY * cos(-env->rotSpeed);
        env->planeX = env->planeX * cos(-env->rotSpeed) - env->planeY * sin(-env->rotSpeed);
        env->planeY = env->oldPlaneX * sin(-env->rotSpeed) + env->planeY * cos(-env->rotSpeed);
    }
    if (key == 13)
        {
            env->posX += env->dirX * env->moveSpeed;
            env->posY += env->dirY * env->moveSpeed;
        }
    if (key == 53)
        exit(EXIT_SUCCESS);
    printf("%d\n", key);
    display(env);
    return (0);
}

void        hook_loop(t_env *env)
{
    mlx_hook(env->win_ptr, 17, 0, out, env);
	mlx_hook(env->win_ptr, 2, 0, deal_key, env);
}