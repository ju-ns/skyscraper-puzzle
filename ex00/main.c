/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpena <gpena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:00:00 by gpena             #+#    #+#             */
/*   Updated: 2025/06/08 21:20:22 by gpena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_clue	clues;
	int		grid[4][4];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!validate_input(argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	parse_input(argv[1], &clues);
	init_grid(grid);
	if (solve(grid, &clues, 0, 0))
	{
		print_solution(grid);
		return (0);
	}
	write(1, "Error\n", 6);
	return (1);
}