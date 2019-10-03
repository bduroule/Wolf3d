/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/03 14:27:39 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/03 14:27:45 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

void	wolf_run(t_env *env)
{
	int x;

	x = -1;
	sole(env);
	while (++x < WIDTH)
	{
		init_raycasting(env, x);
		init_calc_raycasting(env);
		raycasting_hit(env);
		raycasting_wall_distance(env, x);
	}
}

int		main(int ac, char **av)
{
	t_map	*map;
	t_env	*env;
	int		fd;

	if (ac != 2)
		return (0);
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	map = NULL;
	init_a(env);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Wolf3d");
	env->ptr_img = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
	env->ttx = 1;
	generate_tex(env);
	env->my_str_img = (unsigned int *)mlx_get_data_addr(env->ptr_img,
		&(env->bpp), &(env->s_l), &(env->endian));
	if (!(split_map(fd, &map, env)))
		return (write(1, "map error\n", 10));
	display(env);
	hook_loop(env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
