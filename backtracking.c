/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:52:07 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/15 16:36:07 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	solve_maze_util(t_data *data, int y, int x, char **sol)
{
	if (y == data->py && x == data->px && data->map[y][x] == 'P')
		return (1);
	if (data->map[y][x] != '1')
	{
		if (sol[y][x] == '1')
			return (0);
		sol[y][x] = '1';
		if (data->map[y][x] == 'C')
			data->ccount--;
		if (solve_maze_util(data, y, x + 1, sol))
			return (1);
		if (solve_maze_util(data, y, x - 1, sol))
			return (1);
		if (solve_maze_util(data, y + 1, x, sol))
			return (1);
		if (solve_maze_util(data, y - 1, x, sol))
			return (1);
		sol[y][x] = '0';
		return (0);
	}
	return (0);
}

int	solve_maze_util2(t_data *data, int y, int x, char **sol)
{
	if (y == data->py && x == data->px && data->map[y][x] == 'P')
		return (1);
	if ((data->map[y][x] != '1') && (data->map[y][x] != 'E'))
	{
		if (sol[y][x] == '1')
			return (0);
		sol[y][x] = '1';
		if (solve_maze_util2(data, y, x + 1, sol))
			return (1);
		if (solve_maze_util2(data, y, x - 1, sol))
			return (1);
		if (solve_maze_util2(data, y + 1, x, sol))
			return (1);
		if (solve_maze_util2(data, y - 1, x, sol))
			return (1);
		sol[y][x] = '0';
		return (0);
	}
	return (0);
}

int	solve_maze_exit(t_data *data, int yy, int xx, char *str)
{
	char	**sol;

	data->x = 0;
	data->y = 0;
	sol = ft_split(str, '\n');
	ft_sol_reset(data, sol);
	if (!(solve_maze_util(data, yy, xx, sol)))
		return (ft_printf("Error\nSolution doesn't exist\n"), ft_free(sol), 0);
	return (ft_free(sol), 1);
}

int	solve_maze_col(t_data *data, int yy, int xx, char *str)
{
	char	**sol;

	data->x = 0;
	data->y = 0;
	sol = ft_split(str, '\n');
	ft_sol_reset(data, sol);
	if (!(solve_maze_util2(data, yy, xx, sol)))
		return (ft_printf("Error\nSolution doesn't exist\n"), ft_free(sol), 0);
	return (ft_free(sol), 1);
}

int	ft_backtracking(t_data *data, char **map, char *str)
{
	int	x;
	int	y;

	ft_coordinates(data, map);
	if (!(solve_maze_exit(data, data->ey, data->ex, str)))
		return (free(str), 0);
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				data->cx = x;
				data->cy = y;
				if (!(solve_maze_col(data, data->cy, data->cx, str)))
					return (free(str), 0);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (free(str), 1);
}
