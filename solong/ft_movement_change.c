/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:44:10 by smackere          #+#    #+#             */
/*   Updated: 2022/02/27 13:17:57 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	movement_right(t_data *vars, char *name)
{
	if (vars->s == 0)
	{
		name = PLAYER;
		return (0);
	}
	if (vars->map[vars->pos.posx][vars->pos.posy + 1] != '1' && name == PLAYER)
	{
		name = PLAYERGO;
		return (0);
	}
	if ((vars->map[vars->pos.posx][vars->pos.posy + 1] != '1')
			&& (name == PLAYERGO || name == PLAYERL))
	{
		name = PLAYER;
		return (0);
	}
	if (vars->map[vars->pos.posx][vars->pos.posy + 1] == '1')
		name = PLAYERL;
	return (0);
}

int	movement_left(t_data *vars, char *name)
{
	if ((vars->map[vars->pos.posx][vars->pos.posy - 1] != '1') &&
		(name == PLAYER || name == PLAYERGO))
	{
		name = PLAYERL;
		return (0);
	}
	if (vars->map[vars->pos.posx][vars->pos.posy - 1] != '1'
			&& name == PLAYERL)
	{
		name = PLAYERLG;
		return (0);
	}
	if (vars->map[vars->pos.posx][vars->pos.posy - 1] == '1')
		name = PLAYER;
	return (0);
}

int	movement_up(t_data *vars, char *name)
{
	if ((vars->map[vars->pos.posx - 1][vars->pos.posy] != '1')
			&& (name == PLAYER || name == PLAYERL || name == PLAYERLG))
	{
		name = PLAYERGO;
		return (0);
	}
	if (vars->map[vars->pos.posx - 1][vars->pos.posy] != '1'
			&& name == PLAYERGO)
	{
		name = PLAYER;
		return (0);
	}
	if (vars->map[vars->pos.posx - 1][vars->pos.posy] == '1')
		name = PLAYER;
	return (0);
}

int	movement_down(t_data *vars, char *name)
{
	if ((vars->map[vars->pos.posx + 1][vars->pos.posy] != '1')
			&& (name == PLAYER || name == PLAYERGO))
	{
		name = PLAYERL;
		return (0);
	}
	if (vars->map[vars->pos.posx + 1][vars->pos.posy] != '1'
			&& name == PLAYERL)
	{
		name = PLAYERLG;
		return (0);
	}
	if (vars->map[vars->pos.posx + 1][vars->pos.posy] == '1')
		name = PLAYERL;
	return (0);
}
