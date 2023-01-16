/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:36:08 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/13 12:10:32 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../mlx.h"
#include	"../mlx_int.h"

#define XPM_X 64
#define XPM_Y 64

void	*mlx;
void	*win;
void	*w; //perenaznachit na img.wall etc
void	*f;
void	*p;
void	*c;
void	*e;
char	**map;
int		i;
int		px;
int		py;
char	direction;

int		x = 0;
int		y = 0;
int		count = 0;
int		ccount = 0;
int		win_x = XPM_X * 10;
int		win_y = (XPM_Y * 5) + 10;
char	test[] = "1111111111\n10010000C1\n1000011001\n1P0011E001\n1111111111";

void	ft_init(void)
{
	p = mlx_xpm_file_to_image(mlx, "xpms/player.xpm", &i, &i);
	f = mlx_xpm_file_to_image(mlx, "xpms/floor.xpm", &i, &i);
	w = mlx_xpm_file_to_image(mlx, "xpms/wall.xpm", &i, &i);
	e = mlx_xpm_file_to_image(mlx, "xpms/exit.xpm", &i, &i);
	c = mlx_xpm_file_to_image(mlx, "xpms/collectible.xpm", &i, &i);
}

void	ft_exit(void)
{
	int	i;

	i = 0;
	mlx_destroy_display(mlx);
	free(mlx);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit(0);
	return ;
}

int	ft_map_update_d(void *mlx, char **map, int px, int py)
{
	int	ret;

	ret = 0;
	if (map[py][px + 1] && (map[py][px + 1]) != '1')
	{
		if ((map[py][px + 1]) == 'E' && ccount == 0)
			ft_exit();
		if ((map[py][px + 1]) == 'E')
			return (ret);
		if ((map[py][px + 1]) == 'C')
		{
			map[py][px + 1] = '0';
			ccount--;
		}
		ret = 1;
		mlx_put_image_to_window(mlx, win, f, (px * XPM_X), (py * XPM_X));
		px++;
		mlx_put_image_to_window(mlx, win, p, (px * XPM_X), (py * XPM_Y));
	}
	return (ret);
}

int	ft_map_update_a(void *mlx, char **map, int px, int py)
{
	int	ret;

	ret = 0;
	if (map[py][px - 1] && (map[py][px - 1]) != '1')
	{
		if ((map[py][px - 1]) == 'E' && ccount == 0)
			ft_exit();
		if ((map[py][px - 1]) == 'E')
			return (ret);
		if ((map[py][px - 1]) == 'C')
		{
			map[py][px - 1] = '0';
			ccount--;
		}
		ret = 1;
		mlx_put_image_to_window(mlx, win, f, (px * XPM_X), (py * XPM_Y));
		px--;
		mlx_put_image_to_window(mlx, win, p, (px * XPM_X), (py * XPM_Y));
	}
	return (ret);
}

int	ft_map_update_w(void *mlx, char **map, int px, int py)
{
	int	ret;

	ret = 0;
	if (map[py - 1][px] && (map[py - 1][px]) != '1')
	{
		if ((map[py - 1][px]) == 'E' && ccount == 0)
			ft_exit();
		if ((map[py - 1][px]) == 'E')
			return (ret);
		if ((map[py - 1][px]) == 'C')
		{
			map[py - 1][px] = '0';
			ccount--;
		}
		ret = 1;
		mlx_put_image_to_window(mlx, win, f, (px * XPM_X), (py * XPM_Y));
		py--;
		mlx_put_image_to_window(mlx, win, p, (px * XPM_X), (py * XPM_Y));
	}
	return (ret);
}

int	ft_map_update_s(void *mlx, char **map, int px, int py)
{
	int	ret;

	ret = 0;
	if (map[py + 1][px] && (map[py + 1][px]) != '1')
	{
		if ((map[py + 1][px]) == 'E' && ccount == 0)
			ft_exit();
		if ((map[py + 1][px]) == 'E')
			return (ret);
		if ((map[py + 1][px]) == 'C')
		{
			map[py + 1][px] = '0';
			ccount--;
		}
		mlx_put_image_to_window(mlx, win, f, (px * XPM_X), (py * XPM_Y));
		py++;
		mlx_put_image_to_window(mlx, win, p, (px * XPM_X), (py * XPM_Y));
		return (py);
	}
	return (ret);
}

static int	ft_numlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while ((n / 10) > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		numlen;

	numlen = ft_numlen(n);
	str = malloc(sizeof(char) * (numlen + 1));
	if (!str)
		return (NULL);
	str[numlen] = '\0';
	if (n == 0)
		str[--numlen] = (n + '0');
	else if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[--numlen] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	key_win(int key)
{
	char	*str;
	char	*test;

	if (key == 65307)
		ft_exit();
	if (key == 100)
	{
		if (ft_map_update_d(mlx, map, px, py))
		{
			px++;
			count++;
		}
	}
	if (key == 97)
	{
		if (ft_map_update_a(mlx, map, px, py))
		{
			px--;
			count++;
		}
	}
	if (key == 115)
	{
		if (ft_map_update_s(mlx, map, px, py))
		{
			py++;
			count++;
		}
	}
	if (key == 119)
	{
		if (ft_map_update_w(mlx, map, px, py))
		{
			py--;
			count++;
		}
	}
	str = ft_itoa(count);
	test = ft_itoa(count - 1);
	mlx_string_put(mlx, win, win_x / 2, win_y - 5, 0x000000, test);
	mlx_string_put(mlx, win, win_x / 2, win_y - 5, 0xFF99FF, str);
	free(str);
	free(test);
	return (0);
}

void	ft_put_map1(char **map, void *mlx, void *win)
{
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				mlx_put_image_to_window(mlx, win, w, (x * XPM_X), (y * XPM_Y));
				x++;
			}
			else if (map[y][x] == '0')
			{
				mlx_put_image_to_window(mlx, win, f, (x * XPM_X), (y * XPM_Y));
				x++;
			}
			else
				x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void	ft_put_map2(char **map, void *mlx, void *win)
{
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				mlx_put_image_to_window(mlx, win, e, (x * XPM_X), (y * XPM_Y));
				x++;
			}
			else if (map[y][x] == 'C')
			{
				mlx_put_image_to_window(mlx, win, c, (x * XPM_X), (y * XPM_Y));
				x++;
				ccount++;
			}
			else
				x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void	ft_put_player(char **map, void *mlx, void *win)
{
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				mlx_put_image_to_window(mlx, win, p, (x * XPM_X), (y * XPM_Y));
				px = x;
				py = y;
				x++;
			}
			else
				x++;
		}
		x = 0;
		y++;
	}
	return ;
}

int	is_sep(char chr, char c)
{
	if (chr == c)
		return (1);
	return (0);
}

int	word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		if (s[i])
			count++;
		while (s[i] && !(is_sep(s[i], c)))
			i++;
	}
	return (count);
}

int	word_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !(is_sep(s[i], c)))
		i++;
	return (i);
}

char	*ft_word(char *s, char c)
{
	int		i;
	int		wordlen;
	char	*word;

	i = 0;
	wordlen = word_len(s, c);
	word = malloc(sizeof(char) * (wordlen + 1));
	if (!word)
		return (NULL);
	while (i < wordlen)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (word_count((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s)
		{
			tab[i] = ft_word((char *)s, c);
			i++;
		}
		while (*s && !(is_sep(*s, c)))
			s++;
	}
	tab[i] = 0;
	return (tab);
}

int	main(void)
{
	map = ft_split(test, '\n');
	mlx = mlx_init();
	if (!mlx)
		return (-1);
	win = mlx_new_window(mlx, win_x, win_y, "so_long");
	if (!win)
		return (-1);
	ft_init();
	ft_put_map1(map, mlx, win);
	ft_put_map2(map, mlx, win);
	ft_put_player(map, mlx, win);
	mlx_key_hook(win, key_win, 0);
	mlx_hook(win, KeyPress, KeyPressMask, 0, 0);
	mlx_loop(mlx);
	return (0);
}
