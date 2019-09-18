/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/16 13:19:06 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/16 13:19:11 by jadonvez    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

void            init_raycasting(t_env *env, int x)
{
    env->cameraX = (2 * x) / (double)(WIDTH) - 1;
    env->rayDirX = env->dirX + env->planeX * env->cameraX;
    env->rayDirY = env->dirY + env->planeY * env->cameraX;
    env->mapX = (int)env->posX;
    env->mapY = (int)env->posY;
    env->deltaDistX = ft_sqrt(1 + (env->rayDirY * env->rayDirY / env->rayDirX * env->rayDirX));
    env->deltaDistY = ft_sqrt(1 + (env->rayDirX * env->rayDirX / env->rayDirY * env->rayDirY));
    env->stepX = 0;
    env->stepY = 0;
    env->hit = 0;
    env->side = 0;
}

void            init_calc_raycasting(t_env *env)
{
    if (env->rayDirX < 0)
    {
        env->stepX = -1;
        env->sideDistX =  (env->posX - env->mapX) * env->deltaDistX;
    }
    else
    {
        env->stepX = 1;
        env->sideDistX = (env->mapX + 1.0 - env->posX) * env->deltaDistX;
    }
        if (env->rayDirY < 0)
    {
        env->stepY = -1;
        env->sideDistY =  (env->posY - env->mapY) * env->deltaDistY;
    }
    else
    {
        env->stepY = 1;
        env->sideDistY = (env->mapY + 1.0 - env->posY) * env->deltaDistY;
    }
}

void            raycasting_hit(t_env *env)
{
    while (env->hit == 0)
    {
        if (env->sideDistX < env->sideDistY)
        {
            env->sideDistX += env->deltaDistX;
            env->mapX += env->stepX;
            env->side = 0;
        }
        else
        {
            env->sideDistY += env->deltaDistY;
            env->mapY += env->stepY;
            env->side = 1;
        }
        if (env->map[env->mapX][env->mapY] > 0)
            env->hit = 1;
    }
}

void        raycasting_wall_distance(t_env *env, int x)
{
    if (env->side == 0)
        env->perpWallDist = (env->mapX - env->posX + (1 - env->stepX) / 2) / env->rayDirX;
    else
        env->perpWallDist = (env->mapY - env->posY + (1 - env->stepY) / 2) / env->rayDirY;
    env->lineHeight = (int) (HEIGHT / env->perpWallDist);
    env->drawStart = -env->lineHeight / 2 + HEIGHT / 2;
    if (env->drawStart < 0)
        env->drawStart = 0;
    env->drawEnd = env->lineHeight / 2 + HEIGHT / 2;
    if (env->drawEnd >= HEIGHT)
        env->drawEnd = HEIGHT - 1;
    draw_wall(env, x);
}