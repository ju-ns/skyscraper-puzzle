/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpena <gpena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:00:00 by gpena             #+#    #+#             */
/*   Updated: 2025/06/08 21:20:53 by gpena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# define GRID_SIZE 4

typedef struct s_clue
{
	int	north[GRID_SIZE];
	int	south[GRID_SIZE];
	int	west[GRID_SIZE];
	int	east[GRID_SIZE];
}	t_clue;

/* Input functions */
int		validate_input(char *str);
void	parse_input(char *str, t_clue *clues);

/* Solving functions */
int		solve(int grid[4][4], t_clue *clues, int row, int col);
int		is_valid_placement(int grid[4][4], t_clue *clues, int row, int col,
			int num);

/* Validation functions */
int		check_duplicates(int grid[4][4], int row, int col, int num);
int		check_visibility(int grid[4][4], t_clue *clues);

/* Visibility counting functions */
int		count_visible_left(int row[4]);
int		count_visible_right(int row[4]);
int		count_visible_north(int grid[4][4], int col);
int		count_visible_south(int grid[4][4], int col);

/* Output function */
void	print_solution(int grid[4][4]);

#endif