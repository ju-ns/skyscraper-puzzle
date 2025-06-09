/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpena <gpena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:00:00 by gpena             #+#    #+#             */
/*   Updated: 2025/06/08 21:29:57 by gpena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_row_duplicate(int grid[4][4], int row, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_col_duplicate(int grid[4][4], int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(int grid[4][4], int row, int col, int num)
{
	if (!check_row_duplicate(grid, row, num))
		return (0);
	if (!check_col_duplicate(grid, col, num))
		return (0);
	return (1);
}

int	is_grid_complete(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_visibility(int grid[4][4], t_clue *clues)
{
	int	i;
	int	row_array[4];
	int	j;

	if (!is_grid_complete(grid))
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			row_array[j] = grid[i][j];
			j++;
		}
		if (count_visible_left(row_array) != clues->west[i])
			return (0);
		if (count_visible_right(row_array) != clues->east[i])
			return (0);
		if (count_visible_north(grid, i) != clues->north[i])
			return (0);
		if (count_visible_south(grid, i) != clues->south[i])
			return (0);
		i++;
	}
	return (1);
}
