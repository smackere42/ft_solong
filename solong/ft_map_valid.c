/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:35:59 by smackere          #+#    #+#             */
/*   Updated: 2022/02/27 13:10:07 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_wstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_wh_valid(t_data *map)
{
	int	i;
	int	j;

	j = 0;
	i = ft_wstrlen(map->map[0]);
	while (map->map[j])
	{
		if (ft_wstrlen(map->map[j]) != i || map->h == map->w)
			ft_free_ex(map);
		j++;
	}
}

void	ft_elem_count(t_data *map, char c)
{
	if (c == 'E')
		map->e++;
	if (c == 'P')
		map->pos.p++;
	if (c == 'C')
		map->c++;
}

void	ft_chars_valid(t_data *map)
{
	int	x;
	int	y;

	ft_wh_valid(map);
	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
		{
			if (map->map[x][y] != '1' && map->map[x][y] != '0' &&
				map->map[x][y] != 'C' && map->map[x][y] != 'E' &&
				map->map[x][y] != 'P')
				ft_free_ex(map);
			ft_elem_count(map, map->map[x][y]);
		}
	}
	if (!map->c || !map->e || !map->pos.p)
		ft_free_ex(map);
}

void	ft_walls_valid(t_data *map)
{
	int	x;
	int	y;

	ft_chars_valid(map);
	map->pos.posx = 0;
	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y] != '\0')
		{
			ft_check_players(map, x, y);
			if (x == 0 && map->map[x][y] != '1')
				ft_free_ex(map);
			if (y == 0 && map->map[x][y] != '1')
				ft_free_ex(map);
			if (y == map->w / 32 - 1 && map->map[x][y] != '1')
				ft_free_ex(map);
			if (x == map->h / 32 - 1 && map->map[x][y] != '1')
				ft_free_ex(map);
		}
	}
}
