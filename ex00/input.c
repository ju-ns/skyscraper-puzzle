/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:00:00 by gpena             #+#    #+#             */
/*   Updated: 2025/06/09 09:02:19 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
//verifica se e um digito valido 
int	is_valid_char(char c) 
{
	return ((c >= '1' && c <= '4') || c == ' ');
}
//contar numeros que recebemos 
int	count_numbers(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
			count++;
		i++;
	}
	return (count); 
}

int	validate_input(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!is_valid_char(str[i]))
			return (0);
		i++;
	}
	if (count_numbers(str) != 16)
		return (0);
	return (1);
}

void	extract_numbers(char *str, int numbers[16])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && count < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			numbers[count] = str[i] - '0';
			count++;
		}
		i++;
	}
}

void	parse_input(char *str, t_clue *clues)
{
	int	numbers[16];
	int	i;

	extract_numbers(str, numbers);
	i = 0;
	while (i < 4)
	{
		clues->north[i] = numbers[i];
		clues->south[i] = numbers[i + 4];
		clues->west[i] = numbers[i + 8];
		clues->east[i] = numbers[i + 12];
		i++;
	}
}