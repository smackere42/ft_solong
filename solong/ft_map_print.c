/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:50:21 by smackere          #+#    #+#             */
/*   Updated: 2022/02/27 13:35:43 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_printer(char *name, int x, int y, t_data *map)
{
	int	width;
	int	height;

	x *= 32;
	y *= 32;
	map->wall = mlx_xpm_file_to_image(map->wind.mlx, name, &height, &width);
	mlx_put_image_to_window(map->wind.mlx, map->wind.win, map->wall, y, x);
}

void	player_pos(int x, int y)
{
	t_player	player;

	player.posx = x;
	player.posy = y;
}

void	ft_check_d(t_data *map, int x, int y)
{
	if (map->map[x][y] == '1')
		ft_printer(WALL, x, y, map);
	if (map->map[x][y] == '0')
		ft_printer(FLOOR, x, y, map);
	if (map->map[x][y] == 'E')
		ft_printer(DOOR, x, y, map);
	if (map->map[x][y] == 'P')
		ft_printer(map->wind.player.name, x, y, map);
	if (map->map[x][y] == 'C')
		ft_printer(COIN, x, y, map);
}

int	ft_putimg(t_data *map)
{
	int	x;
	int	y;

	ft_walls_valid(map);
	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y] != '\0')
		{
			ft_check_d(map, x, y);
		}
	}
	printf("HERE\n");
	printf("PLAYER.POSY%d\n", map->pos.posy);
	printf("Player.posx: %d\n", map->pos.posx);
	return (0);
}
