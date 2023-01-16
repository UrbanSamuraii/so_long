/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:57:18 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/16 11:10:46 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_map_check(char *map)
{
	int	ret;

	ret = 0;
	ft_check_forbidden_char(map, &ret);
	if (ret == -1)
		return (ft_printf("Error\nUnknown characters detected\n"), ret);
	ft_check_borders(map, &ret);
	if (ret == -2)
		return (ft_printf("Error\nInvalid borders or extra \\n\n"), ret);
	ft_check_double(map, &ret);
	if (ret == -3)
		return (ft_printf("Error\nInvalid number of E/P/C characters\n"), ret);
	ft_check_form(map, &ret);
	if (ret == -4)
		ft_printf("Error\nInvalid map form detected\n");
	return (ret);
}

int	ft_file_check(char *big, char *little)
{
	int	i;
	int	j;

	i = ft_strlen(big) - 1;
	j = ft_strlen(little) - 1;
	while (big[i] && little[j] && big[i] == little[j])
	{
		j--;
		i--;
	}
	if (!little[j])
		return (1);
	return (ft_printf("Error\nWrong file type\n"), 0);
}

char	**ft_map(char *str, t_data *data)
{
	int		i;
	char	**map;

	i = 0;
	if (ft_map_check(str) < 0)
		return (free(str), NULL);
	map = ft_split(str, '\n');
	data->win_x = S * (ft_strlen(map[0]));
	while (map[i])
		i++;
	data->win_y = (S * i) + 10;
	data->map = map;
	data->ccount = 0;
	if (!(ft_backtracking(data, map, str)))
		return (ft_free(data->map), NULL);
	return (map);
}

int	ft_error(char *str, t_data *data)
{
	int	sc_x;
	int	sc_y;

	if (str == NULL)
		return (ft_printf("Error\nfile is empty\n"), 1);
	data->map = ft_map(str, data);
	if (data->map == NULL)
		return (1);
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("Error\nCouldn't find mlx pointer\n");
		return (ft_free(data->map), exit(0), 1);
	}
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y, "so_long");
	if (!data->win)
	{
		ft_printf("Error\nCouldn't create window\n");
		mlx_destroy_display(data->mlx);
		return (free(data->mlx), ft_free(data->map), exit(0), 1);
	}
	mlx_get_screen_size(data->mlx, &sc_x, &sc_y);
	if (data->win_x > sc_x || data->win_y > (sc_y - 56))
		return (ft_printf("Error\nWindow size too big\n"), ft_exit(data, 0), 1);
	return (0);
}

char	*ft_map_deep(char *argv)
{
	int		fd;
	char	*str;
	char	*buff;
	char	*temp;

	str = "";
	fd = open(argv, O_RDONLY);
	buff = get_next_line(fd);
	if (buff == 0)
		return (close(fd), NULL);
	temp = ft_strjoin(str, buff);
	str = ft_strdup(temp);
	while (buff)
	{
		free(buff);
		buff = get_next_line(fd);
		if (buff)
		{
			temp = ft_strjoin(str, buff);
			free(str);
			str = ft_strdup(temp);
		}
	}
	return (close(fd), free(buff), str);
}
