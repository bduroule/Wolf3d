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

void init_a(t_env *env)
{  
    env->posX = 22.0;
    env->posY = 11.5;
    env->dirX = -1.0
    env->dirY = 0.0;
    env->planeX = 0.0;
    env->planeY = 0.66;
    env->time = 0;
    env->oldTime = 0;

}

void algo(t_env *env)
{
    
}