/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 17:41:13 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/03 14:20:59 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

void	init_a(t_env *e)
{
	e->dirx = -1.0;
	e->diry = 0.0;
	e->planex = 0.0;
	e->planey = 0.66;
	e->time = 0;
	e->oldtime = 0;
	e->speed_id = 0.02;
}

void	texture(t_env *e, int texnb)
{
	e->texnum = 0;
	if (e->side == 0)
		e->wallx = e->posy + e->perpwalldist * e->raydiry;
	else
		e->wallx = e->posx + e->perpwalldist * e->raydirx;
	e->wallx -= floor(e->wallx);
	e->t_x = (int)(e->wallx * (double)e->tex[texnb].width);
	if (e->side == 0 && e->raydirx > 0)
		e->t_x = e->tex[texnb].width - e->t_x - 1;
	if (e->side == 1 && e->raydiry < 0)
		e->t_x = e->tex[texnb].width - e->t_x - 1;
}

void	sole(t_env *e)
{
	int i;
	int j;

	i = -1;
	while (++i < HEIGHT && (j = -1))
		while (++j < WIDTH)
			e->my_str_img[i * WIDTH + j] = i < HEIGHT * .5 ? 0x3498DB :
		0x909497;
}

int		generate_tex_p(t_env *e)
{
	if (!(e->tex[0].img = mlx_xpm_file_to_image(e->mlx_ptr, "./texture/t1.xpm",
		&e->tex[0].width, &e->tex[0].heigthwrhm)))
		return (0);
	if (!(e->tex[1].img = mlx_xpm_file_to_image(e->mlx_ptr, "./texture/t2.xpm",
		&e->tex[1].width, &e->tex[1].heigthwrhm)))
		return (0);
	if (!(e->tex[2].img = mlx_xpm_file_to_image(e->mlx_ptr, "./texture/t3.xpm",
		&e->tex[2].width, &e->tex[2].heigthwrhm)))
		return (0);
	if (!(e->tex[3].img = mlx_xpm_file_to_image(e->mlx_ptr, "./texture/t4.xpm",
		&e->tex[3].width, &e->tex[3].heigthwrhm)))
		return (0);
	if (!(e->tex[0].adr = (unsigned int *)mlx_get_data_addr(e->tex[0].img,
		&(e->tex[0].bpp), &(e->tex[0].s_l), &(e->tex[0].endian))))
		return (0);
	if (!(e->tex[1].adr = (unsigned int *)mlx_get_data_addr(e->tex[1].img,
		&(e->tex[1].bpp), &(e->tex[1].s_l), &(e->tex[1].endian))))
		return (0);
	if (!(e->tex[2].adr = (unsigned int *)mlx_get_data_addr(e->tex[2].img,
		&(e->tex[2].bpp), &(e->tex[2].s_l), &(e->tex[2].endian))))
		return (0);
	if (!(e->tex[3].adr = (unsigned int *)mlx_get_data_addr(e->tex[3].img,
		&(e->tex[3].bpp), &(e->tex[3].s_l), &(e->tex[3].endian))))
		return (0);
	return (1);
}

int		generate_tex(t_env *e)
{
	if (!(e->tex[0].img = mlx_xpm_file_to_image(e->mlx_ptr, "./texture/m.xpm",
		&e->tex[0].width, &e->tex[0].heigthwrhm)))
		return (0);
	if (!(e->tex[1].img = mlx_xpm_file_to_image(e->mlx_ptr, "./texture/m1.xpm",
		&e->tex[1].width, &e->tex[1].heigthwrhm)))
		return (0);
	if (!(e->tex[2].img = mlx_xpm_file_to_image(e->mlx_ptr, "./texture/m2.xpm",
		&e->tex[2].width, &e->tex[2].heigthwrhm)))
		return (0);
	if (!(e->tex[3].img = mlx_xpm_file_to_image(e->mlx_ptr, "./texture/m3.xpm",
		&e->tex[3].width, &e->tex[3].heigthwrhm)))
		return (0);
	if (!(e->tex[0].adr = (unsigned int *)mlx_get_data_addr(e->tex[0].img,
		&(e->tex[0].bpp), &(e->tex[0].s_l), &(e->tex[0].endian))))
		return (0);
	if (!(e->tex[1].adr = (unsigned int *)mlx_get_data_addr(e->tex[1].img,
		&(e->tex[1].bpp), &(e->tex[1].s_l), &(e->tex[1].endian))))
		return (0);
	if (!(e->tex[2].adr = (unsigned int *)mlx_get_data_addr(e->tex[2].img,
		&(e->tex[2].bpp), &(e->tex[2].s_l), &(e->tex[2].endian))))
		return (0);
	if (!(e->tex[3].adr = (unsigned int *)mlx_get_data_addr(e->tex[3].img,
		&(e->tex[3].bpp), &(e->tex[3].s_l), &(e->tex[3].endian))))
		return (0);
	return (1);
}
