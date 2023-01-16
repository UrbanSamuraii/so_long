/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:00:54 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/16 10:41:11 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_map_update_d(t_data *data)
{
	data->ret = 0;
	if (data->map[data->py][data->px + 1] != '1')
	{
		if ((data->map[data->py][data->px + 1]) == 'E' && data->ccount == 0)
			ft_exit(data, 1);
		if ((data->map[data->py][data->px + 1]) == 'V')
			ft_exit(data, 3);
		if ((data->map[data->py][data->px + 1]) == 'E')
			return (data->ret);
		if ((data->map[data->py][data->px + 1]) == 'C')
		{
			data->map[data->py][data->px + 1] = '0';
			data->ccount--;
		}
		data->ret = 1;
		data->count++;
		mlx_put_image_to_window(data->mlx, data->win, data->f,
			(data->px * S), (data->py * S));
		data->px++;
		mlx_put_image_to_window(data->mlx, data->win, data->p1,
			(data->px * S), (data->py * S));
		data->px--;
	}
	return (data->ret);
}

int	ft_map_update_a(t_data *data)
{
	data->ret = 0;
	if (data->map[data->py][data->px - 1] != '1')
	{
		if ((data->map[data->py][data->px - 1]) == 'E' && data->ccount == 0)
			ft_exit(data, 1);
		if ((data->map[data->py][data->px - 1]) == 'V')
			ft_exit(data, 3);
		if ((data->map[data->py][data->px - 1]) == 'E')
			return (data->ret);
		if ((data->map[data->py][data->px - 1]) == 'C')
		{
			data->map[data->py][data->px - 1] = '0';
			data->ccount--;
		}
		data->ret = 1;
		data->count++;
		mlx_put_image_to_window(data->mlx, data->win, data->f,
			(data->px * S), (data->py * S));
		data->px--;
		mlx_put_image_to_window(data->mlx, data->win, data->p1,
			(data->px * S), (data->py * S));
		data->px++;
	}
	return (data->ret);
}

int	ft_map_update_w(t_data *data)
{
	data->ret = 0;
	if (data->map[data->py - 1][data->px] != '1')
	{
		if ((data->map[data->py - 1][data->px]) == 'E' && data->ccount == 0)
			ft_exit(data, 1);
		if ((data->map[data->py - 1][data->px]) == 'V')
			ft_exit(data, 3);
		if ((data->map[data->py - 1][data->px]) == 'E')
			return (data->ret);
		if ((data->map[data->py - 1][data->px]) == 'C')
		{
			data->map[data->py - 1][data->px] = '0';
			data->ccount--;
		}
		data->ret = 1;
		data->count++;
		mlx_put_image_to_window(data->mlx, data->win, data->f,
			(data->px * S), (data->py * S));
		data->py--;
		mlx_put_image_to_window(data->mlx, data->win, data->p1,
			(data->px * S), (data->py * S));
		data->py++;
	}
	return (data->ret);
}

int	ft_map_update_s(t_data *data)
{
	data->ret = 0;
	if (data->map[data->py + 1][data->px] != '1')
	{
		if ((data->map[data->py + 1][data->px]) == 'E' && data->ccount == 0)
			ft_exit(data, 1);
		if ((data->map[data->py + 1][data->px]) == 'V')
			ft_exit(data, 3);
		if ((data->map[data->py + 1][data->px]) == 'E')
			return (data->ret);
		if ((data->map[data->py + 1][data->px]) == 'C')
		{
			data->map[data->py + 1][data->px] = '0';
			data->ccount--;
		}
		data->ret = 1;
		data->count++;
		mlx_put_image_to_window(data->mlx, data->win, data->f,
			(data->px * S), (data->py * S));
		data->py++;
		mlx_put_image_to_window(data->mlx, data->win, data->p1,
			(data->px * S), (data->py * S));
		data->py--;
	}
	return (data->ret);
}

int	ft_exit(t_data *data, int ref)
{
	if (ref)
		ft_destroy(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free(data->map);
	if (ref == 1)
		ft_won(data);
	else if (ref == 2)
		ft_printf("\e[1;35m== you quitted the game ==\n\e[0m");
	else if (ref == 3)
		ft_printf("\e[1;35m== you died ==\n\e[0m");
	exit(0);
	return (0);
}
