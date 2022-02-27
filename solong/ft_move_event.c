/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 08:14:19 by smackere          #+#    #+#             */
/*   Updated: 2022/02/27 13:22:17 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	img_replace(t_data *elem, int i)
{
	if (i == 1 && elem->map[elem->pos.posx][elem->pos.posy] != 'E')
		elem->map[elem->pos.posx][elem->pos.posy] = 'P';
	if (i == -1 && elem->map[elem->pos.posx][elem->pos.posy] != 'E')
		elem->map[elem->pos.posx][elem->pos.posy] = 'F';
	if (elem->c == 0 && elem->map[elem->pos.posx][elem->pos.posy] != 'E')
	{
		write(1, "You finished the game!!", 23);
		elem->s++;
	}
	elem->s++;
}

void	ft_imgx_change(t_data *man, int i)
{
	if ((i == -1 && man->map[man->pos.posx - 1][man->pos.posy] != '1')
			&& ft_check_open(man) == 1)
	{
		ft_check_coin(man);
		img_replace(man, -1);
		man->pos.posx -= 1;
		img_replace(man, 1);
	}
	if (i == 1 && man->map[man->pos.posx + 1][man->pos.posy] != '1'
			&& ft_check_open(man) == 1)
	{
		ft_check_coin(man);
		img_replace(man, -1);
		man->pos.posx += 1;
		img_replace(man, 1);
	}
}

void	ft_imgy_change(t_data *man, int i)
{
	if (i == -1 && man->map[man->pos.posx][man->pos.posy - 1] != '1'
			&& ft_check_open(man) == 1)
	{
		ft_check_coin(man);
		img_replace(man, -1);
		man->pos.posy -= 1;
		img_replace(man, 1);
	}
	if (i == 1 && man->map[man->pos.posx][man->pos.posy + 1] != '1'
			&& ft_check_open(man) == 1)
	{
		ft_check_coin(man);
		img_replace(man, -1);
		man->pos.posy += 1;
		img_replace(man, 1);
	}
}

int	move_event(int key, t_data *pos)
{
	printf("key = %d\n", key);
	if (key == 13 || key == 126)
	{
		movement_up(pos, pos->wind.player.name);
		ft_imgx_change(pos, -1);
	}
	if (key == 1 || key == 125)
	{
		movement_down(pos, pos->wind.player.name);
		ft_imgx_change(pos, 1);
	}
	if (key == 0 || key == 123)
	{
		movement_left(pos, pos->wind.player.name);
		ft_imgy_change(pos, -1);
	}
	if (key == 2 || key == 124)
	{
		movement_right(pos, pos->wind.player.name);
		ft_imgy_change(pos, 1);
	}
	mlx_clear_window(pos->wind.mlx, pos->wind.win);
	ft_draw_img(pos);
	return (0);
}

void	moveing(t_data *pos)
{
}
