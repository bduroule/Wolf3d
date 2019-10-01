/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 17:41:13 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 17:41:14 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

void init_a(t_env *env)
{  
    env->posX = 10;
    env->posY = 10;
    env->dirX = -1.0;
    env->dirY = 0.0;
    env->planeX = 0.0;
    env->planeY = 0.66;
    env->time = 0;
    env->oldtime = 0;
}
