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
# include <errno.h>
# include <stdio.h>
# include <sys/time.h>
# include "struct.h"

# define WIDTH 1280
# define HEIGHT 720

int				split_map(int fd, t_map **map, t_env *env);
void			free_file(t_env *env, t_map *map, char **tab, char *line);
int				check_line(char **tab, int *count);
int				count_line(char **tab);
void			free_tab(char ***tab);
void			init_raycasting(t_env *env, int x);
void			init_calc_raycasting(t_env *env);
void			raycasting_hit(t_env *env);
void			raycasting_wall_distance(t_env *env, int x);
void			wolf_run(t_env *env);
void			draw_wall(t_env *env, int x);
void			init_a(t_env *env);
void			display(t_env *env);
void			hook_loop(t_env *env);
void			color_pixel(t_env *env, int x, int y, unsigned int color);
int				generate_tex(t_env *env);
void			draw_tex(t_env *env, int x);
void			texture(t_env *env, int texnb);
void			sole(t_env *env);
unsigned int	get_color(t_texture tex, int x, int y);
unsigned int	wall_color(int r, int g, int b);
int				generate_tex_p(t_env *env);
void			error_file(int fd, char *av);
void			error_map(t_env *env);
int				out(void *param);
int				mouse_m(int x, t_env *e);
int				mouse_moove(int x, int y, t_env *e);

#endif
