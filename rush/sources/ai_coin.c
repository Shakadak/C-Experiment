/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_coin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 17:27:30 by npineau           #+#    #+#             */
/*   Updated: 2014/03/09 23:32:52 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p4.h"

static int	ai_check(t_grid *grid, int row, int col);

int			ai_put(t_grid *grid, int col, char player)
{
	int	row;

	row = grid->y - 1;
	while (grid->grid[row][col])
		row--;
	grid->grid[row][col] = player;
	return (ai_check(grid, row, col));
}

static int	ai_check(t_grid *grid, int row, int col)
{
	int		ret;
	int		res;

	if ((res = check_vertical(grid, row, col)) > 3)
		return (0);
	ret = res;
	if ((res = check_horizontal(grid, row, col)) > 3)
		return (0);
	ret += res;
	if ((res = check_diagonal_up(grid, row, col)) > 3)
		return (0);
	ret += res;
	if ((res = check_diagonal_down(grid, row, col)) > 3)
		return (0);
	return (ret + res);
}

void		ai_remove(t_grid *grid, int col)
{
	int	row;

	row = 0;
	while (!grid->grid[row][col])
		row++;
	grid->grid[row][col] = 0;
}
