/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_deep_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:00 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/15 16:40:37 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_sol_reset(t_data *data, char **sol)
{
	data->x = 0;
	data->y = 0;
	while (sol[data->y])
	{
		while (sol[data->y][data->x])
		{
			sol[data->y][data->x] = '0';
			data->x++;
		}
		data->y++;
		data->x = 0;
	}
}
