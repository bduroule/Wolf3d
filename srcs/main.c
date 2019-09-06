#include "wolf.h"
# include <stdio.h>

int     main(int ac, char **av)
{
    t_map *map;
    t_env *env;
    int fd;
    int i = -1;
    int j = -1;

    if (ac != 2)
        return (0);
    if (!(env = (t_env *)malloc(sizeof(t_env))))
        return (0);
    if ((fd = open(av[1], O_RDONLY)) == -1)
        return (0);
    map = NULL;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Wolf3d");
	env->ptr_img = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
	env->my_str_img = mlx_get_data_addr(env->ptr_img, &(env->bpp), &(env->s_l), &(env->endian));
    if (!(split_map(fd, &map, env)))
        return (write(1, "map error\n", 10));
    dprintf(1, "COUCOU11 h = %d || w = %d\n", env->height, env->width);
    while (++i < env->height)
    {
        j = -1;
        while (++j < env->width){
            printf("%d ", env->map[i][j]);
        }
         printf("\n");
    }
    mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->ptr_img, 0, 0);
    mlx_loop(env->mlx_ptr);
    return (0);
}