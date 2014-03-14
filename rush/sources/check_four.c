/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:12:40 by npineau           #+#    #+#             */
/*   Updated: 2014/03/14 13:38:44 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p4.h"

static int	check_vertical(t_grid *grid, int row, int col);
static int	check_horizontal(t_grid *grid, int row, int col);
static int	check_diagonal_up(t_grid *grid, int row, int col);
static int	check_diagonal_down(t_grid *grid, int row, int col);

int			check_four(t_grid *grid, int row, int col)
{
	if (check_vertical(grid, row, col) > 3)
		return ((int)grid->grid[row][col]);
	if (check_horizontal(grid, row, col) > 3)
		return ((int)grid->grid[row][col]);
	if (check_diagonal_up(grid, row, col) > 3)
		return ((int)grid->grid[row][col]);
	if (check_diagonal_down(grid, row, col) > 3)
		return ((int)grid->grid[row][col]);
	return (0);
}

static int	check_vertical(t_grid *grid, int row, int col)
{
	char	origin;
	int		i;
	int		size;

	size = 1;
	i = row;
	origin = grid->grid[row][col];
	while (++i < (int)grid->y && grid->grid[i][col] == origin)
		size++;
	i = row;
	while (--i >= 0 && grid->grid[i][col] == origin)
		size++;
}

static int	check_horizontal(t_grid *grid, int row, int col)
{
	char	origin;
	int		j;
	int		size;

	size = 1;
	j = col;
	origin = grid->grid[row][col];
	while (++j < (int)grid->x && grid->grid[row][j] == origin)
		size++;
	j = col;
	while (--j >= 0 && grid->grid[row][j] == origin)
		size++;
	return (size);
}

static int	check_diagonal_up(t_grid *g, int row, int col)
{
	char	origin;
	int		i;
	int		j;
	int		size;

	size = 1;
	i = row;
	j = col;
	origin = g->grid[row][col];
	while (++i < (int)g->y && ++j < (int)g->x && g->grid[i][j] == origin)
		size++;
	i = row;
	j = col;
	while (--i >= 0 && --j >= 0 && g->grid[i][j] == origin)
		size++;
	return (size);
}

static int	check_diagonal_down(t_grid *grid, int row, int col)
{
	char	origin;
	int		i;
	int		j;
	int		size;

	size = 1;
	i = row;
	j = col;
	origin = grid->grid[row][col];
	while (++i < (int)grid->y && --j >= 0 && grid->grid[i][j] == origin)
		size++;
	i = row;
	j = col;
	while (--i >= 0 && ++j < (int)grid->x && grid->grid[i][j] == origin)
		size++;
	return (size);
}
