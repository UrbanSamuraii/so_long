/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:36:08 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/15 15:28:14 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_press(int key, t_data *data)
{
	char	*str;
	char	*erase;

	if (key == 65307)
		ft_exit(data, 2);
	if (key == 100)
		data->px += (ft_map_update_d(data));
	if (key == 97)
		data->px -= (ft_map_update_a(data));
	if (key == 115)
		data->py += (ft_map_update_s(data));
	if (key == 119)
		data->py -= (ft_map_update_w(data));
	if (data->ccount == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->e,
			(data->ex * S), (data->ey * S));
	str = ft_itoa(data->count);
	erase = ft_itoa(data->count - 1);
	mlx_string_put(data->mlx, data->win, data->win_x / 2,
		data->win_y - 5, 0x000000, erase);
	mlx_string_put(data->mlx, data->win, data->win_x / 2,
		data->win_y - 5, 0xFF99FF, str);
	return (free(str), free(erase), 0);
}

void	ft_put_map2(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->c,
					(x * S), (y * S));
				data->ccount++;
			}
			else if (data->map[y][x] == 'V')
				mlx_put_image_to_window(data->mlx, data->win, data->e1,
					(x * S), (y * S));
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_put_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->p1,
					(x * S), (y * S));
				data->px = x;
				data->py = y;
			}
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->ws,
					(x * S), (y * S));
			x++;
		}
		x = 0;
		y++;
	}
}

int	ft_animation(t_data *data)
{
	if (data->frame >= 80000)
		data->frame = 0;
	data->frame++;
	if ((data->frame % 80000) == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->p1,
			(data->px * S), (data->py * S));
	else if ((data->frame % 80000) == 20000)
		mlx_put_image_to_window(data->mlx, data->win, data->p2,
			(data->px * S), (data->py * S));
	else if ((data->frame % 80000) == 40000)
		mlx_put_image_to_window(data->mlx, data->win, data->p3,
			(data->px * S), (data->py * S));
	else if ((data->frame % 80000) == 60000)
		mlx_put_image_to_window(data->mlx, data->win, data->p4,
			(data->px * S), (data->py * S));
	return (0);
}

int	main(int argc, char **argv)
{
	char	*str;
	t_data	data;

	if (argc == 2)
	{
		if (!(ft_file_check(argv[1], ".ber")))
			return (-1);
		str = ft_map_deep(argv[1]);
		if (ft_error(str, &data))
			return (-1);
		if (ft_init(&data))
			return (ft_exit(&data, 4), -1);
		ft_put_map1(&data);
		ft_put_map2(&data);
		ft_put_player(&data);
		mlx_key_hook(data.win, key_press, &data);
		mlx_loop_hook(data.mlx, ft_animation, &data);
		mlx_hook(data.win, KeyPress, KeyPressMask, 0, 0);
		mlx_hook(data.win, 17, SubstructureNotifyMask, ft_exit, &data);
		mlx_loop(data.mlx);
		return (0);
	}
	return (ft_printf("Error\nWrong number of arguments\n"), -1);
}
