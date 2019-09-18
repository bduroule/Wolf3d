#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/include/libft.h"
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//----------------------------------------------------------------------------------------------
#include <stdio.h>
//----------------------------------------------------------------------------------------------

#define WIDTH 512
#define HEIGHT 384

typedef struct			s_env
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*ptr_img;
	char				*my_str_img;
    int					bpp;
	int					s_l;
    int					endian;
    double              posX;
    double              posY;
    double              dirX;
    double              dirY;
    double              planeX;
    double              planeY;
    double              time;
    double              oldtime;
    int                 **map;
    int                 width;
    int                 height;
    double              cameraX;
    double              rayDirX;
    double              rayDirY;
    int                 mapX;
    int                 mapY;
    double              sideDistX;
    double              sideDistY;
    double              deltaDistX;
    double              deltaDistY;
    double              perpWallDist;
    int                 stepX;
    int                 stepY;
    int                 hit;
    int                 side;
    int                 lineHeight;
    int                 drawStart;
    int                 drawEnd;
}						t_env;

typedef struct          s_color
{
    int                 r;
    int                 g;
    int                 b;
}                       t_color;

typedef struct          s_map
{
    int                 *n;
    struct s_map        *next;
}                       t_map;

int					split_map(int fd, t_map **map, t_env *env);
void	            free_file(t_env *env, t_map *map, char **tab, char *line);
int		            check_line(char **tab, int *count);
int		            count_line(char **tab);
void				free_tab(char ***tab);
void            init_raycasting(t_env *env, int x);
void            init_calc_raycasting(t_env *env);
void            raycasting_hit(t_env *env);
void        raycasting_wall_distance(t_env *env, int x);
void    wolf_run(t_env *env);
void        draw_wall(t_env *env, int x);

#endif