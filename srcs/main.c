#include "wolf.h"

int     main(int ac, char **av)
{
    t_map *map;
    t_env *env;
    int fd;

    if (ac != 2)
        return (0);
    if (!(env = (t_env *)malloc(sizeof(t_env))))
        return (0);
    if ((fd = open(av[1], O_RDONLY) < 1))
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Wolf3d");
	env->ptr_img = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
	env->my_str_img = mlx_get_data_addr(env->ptr_img, &(env->bpp), &(env->s_l), &(env->endian));
    mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->ptr_img, 0, 0);
    	mlx_loop(env->mlx_ptr);
    split_map(fd, map, env);

    int i = -1;
    int j = -1;

    while (++i < env->height)
    {
        j = -1;
        while (++j < env->width)
            ft_putnbr(env->map[i][j]);
    }
    return (0);
}