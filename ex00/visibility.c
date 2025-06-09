/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpena <gpena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:00:00 by gpena             #+#    #+#             */
/*   Updated: 2025/06/08 21:22:34 by gpena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_visible_left(int row[4])
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < 4)
	{
		if (row[i] > max_height)
		{
			max_height = row[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible_right(int row[4])
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 3;
	while (i >= 0)
	{
		if (row[i] > max_height)
		{
			max_height = row[i];
			count++;
		}
		i--;
	}
	return (count);
}

int	count_visible_north(int grid[4][4], int col)
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] > max_height)
		{
			max_height = grid[i][col];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible_south(int grid[4][4], int col)
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[i][col] > max_height)
		{
			max_height = grid[i][col];
			count++;
		}
		i--;
	}
	return (count);
}