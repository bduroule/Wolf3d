/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_draw.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/18 15:27:43 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/18 15:27:46 by jadonvez    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

void        wall_color(t_color *color, int r, int g, int b)
{
    (*color).r = r;
    (*color).g = g;
    (*color).b = b;
}

void        color_pixel(t_env *env, int x, int y, t_color color)
{
    int i;

    if (!((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT)))
        return ;
    i = (x * 4) + (y * env->s_l);
    env->my_str_img[i] = (char)color.b;
    env->my_str_img[i + 1] = (char)color.g;
    env->my_str_img[i + 2] = (char)color.r;
}

void        draw_wall(t_env *env, int x)
{
    t_color color;

    color = (t_color){.r = 0, .g = 0, .b = 0};
    if (env->side == 1)
    {
        if (env->stepY == 1)
            wall_color(&color, 255, 0, 255);
        else if (env->stepY == -1)
            wall_color(&color, 0, 0, 255);
    }
    else if (env->side == 0)
    {
        if (env->stepX == 1)
            wall_color(&color, 0, 255, 0);
        else if (env->stepX == -1)
            wall_color(&color, 255, 255, 0);
    }
    else if (env->map[env->mapX][env->mapY] == 4)
        wall_color(&color, 0, 0, 0);
    while (env->drawStart <= env->drawEnd)
    {
        color_pixel(env, x, env->drawStart, color);
        env->drawStart++;
    }
}