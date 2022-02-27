/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:55:16 by smackere          #+#    #+#             */
/*   Updated: 2022/02/27 13:42:06 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_exit(t_data *vars)
{
	int	x;

	x = -1;
	// while (vars->map[++x])
		// free(vars->map[x]);
	// free(vars->map);
	exit (0);
}

int	key_hook(int key, t_data *pos)
{
	printf("key = %d\n", key);
	if (key == 13 || key == 126)
	{
		movement_up(pos, pos->wind.player.name);
		ft_imgx_change(pos, -1);
		pos->map[pos->pos.posx] -= 1;
	}
	if (key == 1 || key == 125)
	{
		movement_down(pos, pos->wind.player.name);
		ft_imgx_change(pos, 1);
		pos->map[pos->pos.posx] += 1;
	}
	if (key == 0 || key == 123)
	{
		movement_left(pos, pos->wind.player.name);
		ft_imgy_change(pos, -1);
		pos->map[pos->pos.posy] -= 1;
	}
	if (key == 2 || key == 124)
	{
		movement_right(pos, pos->wind.player.name);
		ft_imgy_change(pos, 1);
		pos->map[pos->pos.posy] += 1;
	}
	mlx_clear_window(pos->wind.mlx, pos->wind.win);
	ft_draw_img(pos);
	if (key == 53)
		ft_exit(pos);
	return (0);
}

void	ft_destroy_event(t_data *event)
{
	// mlx_hook(event->wind.win, 0 , 0, move_event, event);
	// mlx_key_hook(event->wind.win, move_event, event);
	// mlx_hook(event->wind.win, 17, 0, ft_exit, event);
}
