/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:35:39 by smackere          #+#    #+#             */
/*   Updated: 2022/02/27 13:43:59 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_check_players(t_data	*vars, int x, int y)
{
	if (vars->map[x][y] == 'P')
	{
		if (vars->pos.posx == 0 && vars->map[x][y] == 'P')
		{
			vars->pos.posx = x;
			vars->pos.posy = y;
		}
		if ((vars->pos.posy < y || vars->pos.posx < x)
			&& vars->map[x][y] == 'P')
		{
			vars->map[vars->pos.posx][vars->pos.posy] = 'C';
			vars->pos.posx = x;
			vars->pos.posy = y;
			vars->c++;
		}
		vars->pos.p--;
	}
}

void	ft_free_ex(t_data *map)
{
	// int	j;

	// j = -1;
	// while (map->map[++j])
	// {
	// 	free(map->map[j]);
	// }
	// free(map->map);
	write(1, "Error\n", 6);
	write(1, "Something's wrong with map >_<\n", 31);
	// exit (0);
}
