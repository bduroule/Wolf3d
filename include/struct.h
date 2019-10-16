/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 11:51:00 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 11:51:02 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	int					tmpx;
	int					space;
	double				speed_id;
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

typedef struct			s_index
{
	int					i;
	int					j;
}						t_index;

typedef struct			s_parse
{
	char				*line;
	char				**tab;
	int					n;
	int					i;
	int					count;
	int					id;
}						t_parse;

#endif
