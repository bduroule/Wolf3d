/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/03 16:11:09 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/03 16:11:11 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/include/libft.h"
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/time.h>

# define WIDTH 1280
# define HEIGHT 720

typedef struct			s_texture
{
	void				*img;
	unsigned int		*adr;
	int					heigthwrhm;
	int					width;
	int					bpp;
	int					s_l;
	int					endian;
}						t_texture;

typedef struct			s_env
{
	t_texture			tex[4];
	void				*mlx_ptr;
	void				*win_ptr;
	void				*ptr_img;
	unsigned int		*my_str_img;
	int					bpp;
	int					s_l;
	int					endian;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				time;
	double				oldtime;
	int					**map;
	int					width;
	int					height;
	double				camerax;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	int					stepx;
	int					stepy;
	int					hit;
	double				side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	double				frametime;
	double				movespeed;
	double				rotspeed;
	double				oldplanex;
	double				olddirx;
	int					ttx;
	int					texnum;
	double				wallx;
	int					t_x;
	int					t_y;
}						t_env;

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_map
{
	int					*n;
	struct s_map		*next;
}						t_map;

int						split_map(int fd, t_map **map, t_env *env);
void					free_file(t_env *env, t_map *map, char **tab,
						char *line);
int						check_line(char **tab, int *count);
int						count_line(char **tab);
void					free_tab(char ***tab);
void					init_raycasting(t_env *env, int x);
void					init_calc_raycasting(t_env *env);
void					raycasting_hit(t_env *env);
void					raycasting_wall_distance(t_env *env, int x);
void					wolf_run(t_env *env);
void					draw_wall(t_env *env, int x);
void					init_a(t_env *env);
void					display(t_env *env);
void					hook_loop(t_env *env);
void					color_pixel(t_env *env, int x, int y, unsigned int
						color);
void					generate_tex(t_env *env);
void					draw_tex(t_env *env, int x);
void					texture(t_env *env, int texnb);
void					sole(t_env *env);
unsigned int			get_color(t_texture tex, int x, int y);
unsigned int			wall_color(int r, int g, int b);
void					generate_tex_p(t_env *env);

#endif
