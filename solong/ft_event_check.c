/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:21:18 by smackere          #+#    #+#             */
/*   Updated: 2022/02/27 12:37:46 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_check_coin(t_data *elem)
{
	if (elem->map[elem->pos.posx][elem->pos.posy] == 'C')
	{
		elem->map[elem->pos.posx][elem->pos.posy] = 'P';
		elem->cc++;
		elem->c--;
	}
}

int	ft_check_open(t_data *elem)
{
	if (elem->c == 0)
	{
		elem->e = 0;
		return (1);
	}
	return (-1);
}

int	ft_check_exity(t_data *elem, char c, int i)
{
	if (c == 'y' && i == -1)
	{
		if ((elem->map[elem->pos.posx][elem->pos.posy - 1] != 'E')
			|| (elem->map[elem->pos.posx][elem->pos.posy - 1] == 'E'
				&& ft_check_open(elem) == 1))
			return (1);
	}
	if (c == 'y' && i == 1)
	{
		if ((elem->map[elem->pos.posx][elem->pos.posy + 1] != 'E')
			|| (elem->map[elem->pos.posx][elem->pos.posy + 1] == 'E'
				&& ft_check_open(elem) == 1))
			return (1);
	}
	return (0);
}

int	ft_check_exitx(t_data *elem, char c, int i)
{
	if (c == 'x' && i == -1)
	{
		if ((elem->map[elem->pos.posx - 1][elem->pos.posy] != 'E')
			|| (elem->map[elem->pos.posx - 1][elem->pos.posy] == 'E'
			&& ft_check_open(elem) == 1))
			return (1);
	}
	if (c == 'x' && i == 1)
	{
		if ((elem->map[elem->pos.posx + 1][elem->pos.posy] != 'E')
			|| (elem->map[elem->pos.posx + 1][elem->pos.posy] == 'E'
			&& ft_check_open(elem) == 1))
			return (1);
	}
	return (0);
}
