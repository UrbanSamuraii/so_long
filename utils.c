/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:11:53 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/15 16:25:19 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init(t_data *data)
{
	int	i;

	i = 64;
	data->count = 0;
	data->ccount = 0;
	data->frame = 0;
	data->f = mlx_xpm_file_to_image(data->mlx, "xpms/floor.xpm", &i, &i);
	data->w = mlx_xpm_file_to_image(data->mlx, "xpms/wall.xpm", &i, &i);
	data->ws = mlx_xpm_file_to_image(data->mlx, "xpms/wall_sun.xpm", &i, &i);
	data->e = mlx_xpm_file_to_image(data->mlx, "xpms/exit.xpm", &i, &i);
	data->c = mlx_xpm_file_to_image(data->mlx, "xpms/collectible.xpm", &i, &i);
	data->p1 = mlx_xpm_file_to_image(data->mlx, "xpms/player1.xpm", &i, &i);
	data->p2 = mlx_xpm_file_to_image(data->mlx, "xpms/player2.xpm", &i, &i);
	data->p3 = mlx_xpm_file_to_image(data->mlx, "xpms/player3.xpm", &i, &i);
	data->p4 = mlx_xpm_file_to_image(data->mlx, "xpms/player4.xpm", &i, &i);
	if (data->f == NULL || data->w == NULL || data->ws == NULL
		|| data->e == NULL || data->c == NULL || data->p1 == NULL
		|| data->p2 == NULL || data->p3 == NULL || data->p4 == NULL)
		return (ft_printf("Error\nXpm file not found\n"), 1);
	return (0);
}

void	ft_won(t_data *data)
{
	ft_printf("\e[1;36m###################################################\n");
	ft_printf("##  #   #   ###   #   #     #   #   ###   #   #  ##\n");
	ft_printf("##  #   #  #   #  #   #     #   #  #   #  ##  #  ##\n");
	ft_printf("##   # #   #   #  #   #     #   #  #   #  # # #  ##\n");
	ft_printf("##    #    #   #  #   #     # # #  #   #  #  ##  ##\n");
	ft_printf("##    #     ###    ###       # #    ###   #   #  ##\n");
	ft_printf("###################################################\n");
	ft_printf("Total score: %i\n\e[0m", data->count);
}

void	ft_destroy(t_data *data)
{
	if (data->f)
		mlx_destroy_image(data->mlx, data->f);
	if (data->e)
		mlx_destroy_image(data->mlx, data->e);
	if (data->c)
		mlx_destroy_image(data->mlx, data->c);
	if (data->w)
		mlx_destroy_image(data->mlx, data->w);
	if (data->ws)
		mlx_destroy_image(data->mlx, data->ws);
	if (data->p1)
		mlx_destroy_image(data->mlx, data->p1);
	if (data->p2)
		mlx_destroy_image(data->mlx, data->p2);
	if (data->p3)
		mlx_destroy_image(data->mlx, data->p3);
	if (data->p4)
		mlx_destroy_image(data->mlx, data->p4);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_coordinates(t_data *data, char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				data->ex = x;
				data->ey = y;
			}
			else if (map[y][x] == 'P')
			{
				data->px = x;
				data->py = y;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
