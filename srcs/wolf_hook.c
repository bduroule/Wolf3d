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
    if (key == 1)
        env->posY += 1;
    if (key == 2)
        env->posX -= 1;
    if (key == 3)
        env->posY -= 1;
    if (key == 13)
        env->posX += 1;
    display(env);
    return (0);
}

void        hook_loop(t_env *env)
{
    mlx_hook(env->win_ptr, 17, 0, out, env);
	mlx_hook(env->win_ptr, 2, 0, deal_key, env);
}