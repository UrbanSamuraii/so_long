/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:56:37 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/13 13:57:55 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_forbidden_char(char *map, int *ret)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'E' && map[i] != 'C'
			&& map[i] != 'P' && map[i] != 'V' && map[i] != '\n')
			*ret = -1;
		i++;
	}
}

void	ft_check_borders(char *map, int *ret)
{
	int		i;

	i = 0;
	while (map[i] && map[i] == '1')
		i++;
	while (map[i] == '\n' && map[i - 1] == '1' && map[i + 1] == '1')
	{
		i++;
		while (map[i] && map[i] != '\n')
			i++;
		if (map[i + 1] == '\0')
		{
			i -= 2;
			while (map[i] == '1')
				i--;
			if (map[i] != '\n')
				*ret = -2;
			return ;
		}
	}
	*ret = -2;
	return ;
}

void	ft_check_double(char *map, int *ret)
{
	int	e_count;
	int	p_count;
	int	c_count;
	int	i;

	i = 0;
	e_count = 0;
	p_count = 0;
	c_count = 0;
	if (*ret >= 0)
	{
		while (map[i])
		{
			if (map[i] == 'E')
				e_count++;
			else if (map[i] == 'P')
				p_count++;
			else if (map[i] == 'C')
				c_count++;
			i++;
		}
	}
	if (e_count != 1 || p_count != 1 || c_count < 1)
		*ret = -3;
	return ;
}

void	ft_check_form(char *map, int *ret)
{
	int	i;
	int	lines;
	int	chars;

	i = 0;
	lines = 0;
	chars = 1;
	while (map[i] && map[i] != '\n')
	{
		i++;
		chars++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			lines++;
		i++;
	}
	if ((chars * lines) != i)
		*ret = -4;
	return ;
}

void	ft_put_map1(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->w,
					(x * S), (y * S));
			else if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->f,
					(x * S), (y * S));
			x++;
		}
		x = 0;
		y++;
	}
}
