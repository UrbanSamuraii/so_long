/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:01:04 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/16 15:16:41 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if S < 0
#  undef S
# endif
# ifndef S
#  define S 64
# endif
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct data_s
{
	void	*mlx;
	void	*win;
	int		count;
	int		ccount;
	int		win_x;
	int		win_y;
	int		x;
	int		y;
	int		px;
	int		py;
	int		ex;
	int		ey;
	int		cy;
	int		cx;
	char	**map;
	void	*e;
	void	*w;
	void	*ws;
	void	*f;
	void	*c;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;
	void	*e1;
	int		frame;
	int		ret;
}			t_data;

/*      map_check.c       */
void	ft_check_forbidden_char(char *map, int *ret);
void	ft_check_borders(char *map, int *ret);
void	ft_check_double(char *map, int *ret);
void	ft_check_form(char *map, int *ret);
void	ft_put_map1(t_data *data);

/*        utils.c         */
int		ft_init(t_data *data);
void	ft_won(t_data *data);
void	ft_destroy(t_data *data);
void	ft_free(char **tab);
void	ft_coordinates(t_data *data, char **map);

/*       so_long.c        */
int		ft_map_check(char *map);
int		ft_file_check(char *big, char *little);
char	**ft_map(char *str, t_data *data);
int		ft_error(char *str, t_data *data);
char	*ft_map_deep(char *argv);

/*       map_update.c     */
int		ft_map_update_w(t_data *data);
int		ft_map_update_a(t_data *data);
int		ft_map_update_s(t_data *data);
int		ft_map_update_d(t_data *data);
int		ft_exit(t_data *data, int ref);

/*     backtracking.c     */
int		is_safe(t_data *data, int y, int x);
int		solve_maze_util(t_data *data, int y, int x, char **sol);
void	ft_sol_reset(t_data *data, char **sol);
int		solve_maze(t_data *data, int yy, int xx, char *str);
int		ft_backtracking(t_data *data, char **map, char *str);

/*  backtracking_deep.c   */
void	ft_sol_reset(t_data *data, char **sol);

#endif
