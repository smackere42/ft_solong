/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:26:40 by smackere          #+#    #+#             */
/*   Updated: 2022/02/27 13:33:39 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# define BUFFER_SIZE 100000
# define MAX_FD      1024
# define FLOOR		"./images_use/floor.xpm"
# define WALL		"./images_use/wall.xpm"
# define DOOR		"./images_use/door.xpm"
# define PLAYER		"./images_use/m-r.xpm"
# define PLAYERL	"./images_use/m-l.xpm"
# define PLAYERLG	"./images_use/m-l-go.xpm"
# define PLAYERGO	"./imges_use/m-r-go.xpm"
# define COIN		"./images_use/coin.xpm"

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_pimg{
	char	*name;
}	t_pimg;

typedef struct s_window{
	void	*mlx;
	void	*win;
	t_pimg	player;
}	t_wind;

typedef struct s_player {
	int	p;
	int	posy;
	int	posx;
}	t_player;

typedef struct s_data{
	t_wind		wind;
	t_player	pos;
	char		**map;
	void		*test;
	int			fd;
	void		*wall;
	int			w;
	int			h;
	int			c;
	int			e;
	int			cc;
	int			s;
}	t_data;

char	*get_next_line(int fd);
int		main(int argc, char **argv);
int		ft_strlen(const char *s);
char	**ft_map_split(char const *s, char c);
size_t	ft_wordcount(char const *s, char c);
int		ft_putimg(t_data *map);
void	ft_printer(char *name, int x, int y, t_data *map);
void	ft_check_d(t_data *map, int x, int y);
void	ft_walls_valid(t_data *map);
int		ft_nstrlen(char *str);
void	ft_free_ex(t_data *map);
void	ft_elem_count(t_data *map, char c);
void	ft_draw_img(t_data *vars);
void	ft_check_players(t_data	*vars, int x, int y);
void	ft_destroy_event(t_data *vars);
void	ft_check_coin(t_data *elem);
int		ft_check_open(t_data *elem);
int		ft_check_exitx(t_data *elem, char c, int i);
int		ft_check_exity(t_data *elem, char c, int i);
int		ft_exit(t_data *vars);
int		movement_right(t_data *vars, char *name);
int		movement_left(t_data *vars, char *name);
int		movement_up(t_data *vars, char *name);
int		movement_down(t_data *vars, char *name);
int		move_event(int key, t_data *pos);
void	ft_imgx_change(t_data *man, int i);
void	ft_imgy_change(t_data *man, int i);
int		key_hook(int key, t_data *pos);

#endif