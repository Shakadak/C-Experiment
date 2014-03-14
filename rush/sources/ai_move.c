/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:25:34 by npineau           #+#    #+#             */
/*   Updated: 2014/03/14 17:59:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p4.h"

#include "libft.h"

static int	check_move(t_grid *grid, int depth, int x, char player);

int			ai_move(t_grid *grid, int depth)
{
	int	chosen[3] =
	{
		-1, 0, 0
	};
	int ret;

	ret = 0;
	while (++chosen[0] < grid->x)
	{
		if (grid->grid[0][chosen[0]] != 0)
		{
			chosen[2]++;
			continue ;
		}
		ret = check_move(grid, depth, chosen[0], 1);
		if (!chosen[1])
			chosen[1] = ret;
		if (ret > chosen[1])
		{
			chosen[1] = ret;
			chosen[2] = chosen[0];
		}
	}
	return (put_coin(grid, chosen[2], 2));
}

#include <unistd.h>

static int	check_move(t_grid *grid, int depth, int x, char player)
{
	int		chosen[2] =
	{
		-1, 1
	};
	int		ret;

	ret = put_coin(grid, x, player);
	display_grid(*grid);
	usleep(5000);
	if (ret)
	{
		remove_coin(grid, x);
		ret = (ret == 1 ? -10000 : 10000);
		return (ret);
	}
	else
	{
		while (++chosen[0] < grid->x)
		{
			if (grid->grid[0][chosen[0]] != 0)
				continue ;
			ret = check_move(grid, depth - 1, chosen[0], player % 2 + 1) + depth;
			if (!chosen[1])
				chosen[1] = ret;
			if (player == 1 && ret > chosen[1])
				chosen[1] = ret;
			else if (player == 2 && ret < chosen[1])
				chosen[1] = ret;
		}
	}
	remove_coin(grid, x);
	return (chosen[1]);
}

static int	heuristic(t_grid *grid, int row, char player)
{
	int		ret;

	ret = ai_check(grid, row);
	ret *= (player == 1 ? -1 : 1);
	return (ret);
}

static int	min(t_grid *grid, int depth, char player)
{
	int	chosen[2] =
	{
		-1, 1000
	};
	int ret;

	while (++chosen[0] < grid->x)
	{
		if (grid->grid[0][chosen[0]] != 0)
			continue ;
		ret = ai_put(grid, chosen[0], player % 2 + 1);
		if (depth)
			ret = max(grid, depth - 1, 2);
		ret = (!ret ? 1000 : ret);
		chosen[1] = (ret < chosen ? ret : chosen[1]);
		remove_coin(grid, chosen[0], player);
	}
	
static int	max(t_grid *grid, int depth, char player)
