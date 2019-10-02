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

unsigned int        wall_color(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

unsigned int get_color(t_texture tex, int x, int y)
{
   // int i;

    if (!((x >= 0 && x < tex.width) && (y >= 0 && y < tex.heigthwrhm)))
        return (0);
    return (tex.adr[y * tex.width + x]);
}

void        color_pixel(t_env *env, int x, int y, unsigned int color)
{
    int i;

    if (!((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT)))
        return ;
    i = (x * 4) + (y * env->s_l);
    env->my_str_img[env->drawStart * WIDTH + x] = color;
}

void draw_tex(t_env *env, int x)
{
    uint32_t color;
    int      i;

    i = 0;
    color = 0x000000;
    if (env->side == 1)
    {
        if (env->stepY == 1)
            i = 0;
        else if (env->stepY == -1)
           i = 1;
    }
    else if (env->side == 0)
    {
        if (env->stepX == 1)
            i = 2;
        else if (env->stepX == -1)
           i = 3;
    }
    //else if (env->map[env->mapX][env->mapY] == 4)
    //    get_color(env, x, env->drawStart, &color);
    while (env->drawStart <= env->drawEnd)
    {
        env->my_str_img[env->drawStart * WIDTH + x] = get_color(env->tex[i], 155, 5);
        // get_color(env->tex[i], x, y);
        //color_pixel(env, x, env->drawStart, color);
        env->drawStart++;
    }
}

void        draw_wall(t_env *env, int x)
{
    unsigned int color;

    color = 0;
    if (env->side == 1)
    {
        if (env->stepY == 1)
            color = wall_color(255, 0, 255);
        else if (env->stepY == -1)
            color = wall_color(0, 0, 255);
    }
    else if (env->side == 0)
    {
        if (env->stepX == 1)
            color = wall_color(0, 255, 0);
        else if (env->stepX == -1)
            color = wall_color(255, 255, 0);
    }
    else if (env->map[env->mapX][env->mapY] == 4)
       color = wall_color(0, 0, 0);
    while (env->drawStart <= env->drawEnd)
    {
        color_pixel(env, x, env->drawStart, color);
        env->drawStart++;
    }
}