/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/05 15:54:40 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 15:54:42 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

void	free_file(t_env *env, t_map *map, char **tab, char *line)
{
	(void)map;
	free(env);
	free(line);
	free_tab(&tab);
	write(1, "map error\n", 10);
	exit(0);
}

int		check_line(char **tab, int *count)
{
	if (*count == 0)
		*count = count_line(tab);
	if (count_line(tab) != *count)
		return (0);
	if (count == 0)
		return (0);
	return (1);
}

int		count_line(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	error_file(int fd, char *av)
{
	errno = 0;
	read(fd, av, 0);
	if (errno != 0)
	{
		perror("error ");
		exit(0);
	}
}

void	error_map(t_env *env)
{
	t_index id;

	id.i = -1;
	if (env->width == 0 || env->height == 0)
		exit(0);
	while (++id.i < env->height && (id.j = -1))
		while (++id.j < env->width)
		{
			if (id.i == env->height - 1 || id.i == 0)
				env->map[id.i][id.j] = 1;
			if (id.j == env->width - 1 || id.j == 0)
				env->map[id.i][id.j] = 1;
			if (env->map[id.i][id.j] == 2)
			{
				env->posx = id.i + 0.5;
				env->posy = id.j + 0.5;
			}
		}
	if (env->posx == -1 && env->posy == -1)
	{
		write(1, "error : bad player position\n", 28);
		exit(0);
	}
}
