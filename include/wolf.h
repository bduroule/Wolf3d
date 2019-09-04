#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/include/libft.h"
# include "../minilibx_macos/mlx.h"

#define WIDTH 1280
#define HEIGHT 720

typedef struct			s_env
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*ptr_img;
	char				*my_str_img;
    int					bpp;
	int					s_l;
    int					endian;
    double              posx;
    double              posy;
    double              dirx;
    double              diry;
    double              px;
    double              py;
    double              time;
    double              otim;
}						t_env;

#endif