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

#include "wolf.h"

void	free_tab(char ***tab)
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

int		store_line(t_map **map, t_env *env, char **tab, int i)
{
	t_map	*tmp;
	t_map	*new;

	i = 0;
	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (0);
	while (tab[i])
		i++;
	env->width = i;
	if (!(new->n = (int *)malloc(sizeof(int) * i)))
		return (0);
	i = -1;
	while (tab[++i])
		new->n[i] = ft_atoi(tab[i]);
	new->next = NULL;
	if (*map == NULL)
		*map = new;
	else
	{
		tmp = *map;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

int		store_coord(t_map *map, t_env *env)
{
	int		i;
	int		j;
	t_map	*tmp;

	i = -1;
	tmp = map;
	if (!(env->map = (int **)malloc(sizeof(int *) * env->height)))
		return (0);
	while (++i < env->height)
		if (!(env->map[i] = (int *)malloc(sizeof(int) * env->width)))
			return (0);
	i = 0;
	while (i < env->height)
	{
		j = -1;
		while (++j < env->width)
			env->map[i][j] = tmp->n[j];
		i++;
		tmp = tmp->next;
	}
	return (1);
}

int		split_map(int fd, t_map **map, t_env *env)
{
	t_parse p;

	p = (t_parse){.n = 0, .i = 0, .count = 0};
	while (get_next_line(fd, &p.line) > 0)
	{
		if (!p.line || !p.line[0])
			continue ;
		if (!(p.tab = ft_strsplit(p.line, ' ')))
			return (0);
		if (check_line(p.tab, &p.count) == 0)
			free_file(env, *map, p.tab, p.line);
		if (!(store_line(map, env, p.tab, p.i)))
			return (0);
		if (p.line)
			free(p.line);
		free_tab(&p.tab);
		p.n++;
	}
	env->height = p.n;
	if (!store_coord(*map, env))
		return (0);
	return (1);
}
