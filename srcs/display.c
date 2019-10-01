/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 17:39:24 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 17:39:27 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

void display(t_env *env)
{
    int i = -1, j;
    while (++i < WIDTH && (j = -1))
        while (++j < HEIGHT)
            color_pixel(env, i, j, (t_color){.r = 0, .g = 0, .b = 0});
    wolf_run(env);
    mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->ptr_img, 0, 0);
}
