/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:26:16 by smackere          #+#    #+#             */
/*   Updated: 2022/02/27 13:41:33 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_nstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_data		vars;
	char		*line;

	if (argc != 2)
		return (0);
	vars.fd = open(argv[1], O_RDONLY);
	if (vars.fd < 0)
		return (0);
	line = get_next_line(vars.fd);
	vars.map = ft_map_split(line, '\n');
	vars.h = ft_wordcount(line, '\n') * 32;
	vars.w = ft_nstrlen(line) * 32;
	vars.wind.mlx = mlx_init();
	vars.wind.win = mlx_new_window(vars.wind.mlx, vars.w, vars.h, "Solong");
	vars.s = 0;
	vars.pos.p = 0;
	vars.wind.player.name = PLAYER;
	vars.pos.posx = 0;
	vars.pos.posy = 0;
	free(line);
	ft_draw_img(&vars);
	mlx_key_hook(vars.wind.win, key_hook, &vars);
	// ft_destroy_event(&vars);
	mlx_loop(vars.wind.mlx);
	return (0);
}
