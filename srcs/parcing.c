/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parcing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/05 15:39:03 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 15:39:05 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void				free_tab(char ***tab)
{
	char	**str;
	int		i;

	i = 0;
	str = *tab;
	while (*str)
	{
		ft_strdel(str);
		i++;
		str = &(*tab)[i];
	}
	ft_memdel((void **)tab);
}

int				store_line(t_map *map, t_env env, char **tab, int i)
{
	t_map	*tmp;
	t_map	*new;

	i = 0;
	if(!(new = (t_map *)malloc(sizeof(t_map))))
		return (0);
	while (tab[i])
		i++;
	if(!(env->map = (int *)malloc(sizeof(int)* i)))
		return (0);
	i = -1;
	while (tab[++i])
		env->map[i] = ft_atoi(tab[i]);
	if (map == NULL)
		map = new;
	else
	{
		tmp = map;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

int					store_coord(t_map *map, t_env *env)
{
	int		i;
	int		j;
	t_map	*tmp;

	i = -1;
	tmp = map;
	if (!(env->map = (int **)malloc(sizeof(int *) * env->height)))
		return (0);
	while (++i < env->height)
		if (!(env->map[i] = (int * )malloc(sizeof(int) * env->width)))
			return (0);
	i = -1;
	while (++i < env->height)
	{
		j = -1;
		while (++j < env->width)
			env->map[i][j] = map->n[j];
		map = map->next;
	}
	return (0);
}

int					split_map(int fd, t_map **map, t_env *env)
{
	char	*line;
	char	**tab;
	int		n;
	int		i;
	int		count;

	n = 0;
	i = 0;
	count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(tab = ft_strsplit(line, ' ')))
			return (0);
		if (check_line(tab, &count) == 0)
			free_file(file, *map, tab, line);
		if (!(store_line(map, file, tab, i)))
			return (0);
		if (line)
			free(line);
		free_tab(&tab);
		n++;
	}
	env->height = n;
	store_coord(*map, file);
	return (1);
}
