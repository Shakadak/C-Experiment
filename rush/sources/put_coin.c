/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_coin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:54:17 by npineau           #+#    #+#             */
/*   Updated: 2014/03/09 23:13:21 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p4.h"

int		put_coin(t_grid *grid, int col, char player)
{
	int	row;

	row = grid->y - 1;
	while (grid->grid[row][col])
		row--;
	grid->grid[row][col] = player;
	return (check_four(grid, row, col));
}

void	remove_coin(t_grid *grid, int col)
{
	int	row;

	row = 0;
	while (!grid->grid[row][col])
		row++;
	grid->grid[row][col] = 0;
}
