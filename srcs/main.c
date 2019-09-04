#include "wolf.h"

int     main(void)
{
    t_env *env;

    if (!(env = (t_env *)malloc(sizeof(t_env))))
        return (0);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Wolf3d");
	env->ptr_img = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
	env->my_str_img = mlx_get_data_addr(env->ptr_img, &(env->bpp), &(env->s_l), &(env->endian));
    mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->ptr_img, 0, 0);
    	mlx_loop(env->mlx_ptr);
    return (0);
}