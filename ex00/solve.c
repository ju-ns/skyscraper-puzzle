/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:00:00 by gpena             #+#    #+#             */
/*   Updated: 2025/06/09 08:26:52 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_row_complete(int grid[4][4], int row)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_col_complete(int grid[4][4], int col)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[i][col] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_row_visibility(int grid[4][4], t_clue *clues, int row)
{
	int	row_array[4];
	int	i;

	if (!is_row_complete(grid, row))
		return (1);
	i = 0;
	while (i < 4)
	{
		row_array[i] = grid[row][i];
		i++;
	}
	if (count_visible_left(row_array) != clues->west[row])
		return (0);
	if (count_visible_right(row_array) != clues->east[row])
		return (0);
	return (1);
}

int	check_col_visibility(int grid[4][4], t_clue *clues, int col)
{
	if (!is_col_complete(grid, col))
		return (1);
	if (count_visible_north(grid, col) != clues->north[col])
		return (0);
	if (count_visible_south(grid, col) != clues->south[col])
		return (0);
	return (1);
}

int	is_valid_placement(int grid[4][4], t_clue *clues, int row, int col,
		int num)
{
	if (!check_duplicates(grid, row, col, num))
		return (0);
	grid[row][col] = num;
	if (!check_row_visibility(grid, clues, row))
	{
		grid[row][col] = 0;
		return (0);
	}
	if (!check_col_visibility(grid, clues, col))
	{
		grid[row][col] = 0;
		return (0);
	}
	grid[row][col] = 0;
	return (1);
}

int	solve(int grid[4][4], t_clue *clues, int row, int col)
{
	int	num;

	if (row == 4)
		return (1);
	if (col == 4)
		return (solve(grid, clues, row + 1, 0));
	num = 1;
	while (num <= 4)
	{
		if (is_valid_placement(grid, clues, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, clues, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}