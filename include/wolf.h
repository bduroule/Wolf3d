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
    int                 **map;
    int                 width;
    int                 height;
}						t_env;

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

#endif