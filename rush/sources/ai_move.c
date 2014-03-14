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
		0, 0, 0
	};
	int ret;

	chosen[1] = check_move(grid, depth, chosen[0], 2);
	while (++chosen[0] < grid->x)
	{
		if (grid->grid[0][chosen[0]] != 0)
			continue ;
		ret = check_move(grid, depth, chosen[0], 2);
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
	int		chosen[3] =
	{
		-1, 0, 0
	};
	int		ret;

	ret = put_coin(grid, x, player);
	if (ret)
	{
		display_grid(*grid);
		remove_coin(grid, x);
		ret = (ret == 1 ? -10000 : 10000);
		ft_putnbr(ret);
		ft_putchar('\n');
		return (ret);
	}
	else
	{
		display_grid(*grid);
		while (++chosen[0] < grid->x)
		{
			if (grid->grid[0][x] != 0 || depth - 1 == 0)
				continue ;
			ret = check_move(grid, depth - 1, chosen[0], player % 2 + 1);
			if (player == 1 && ret > chosen[1])
				chosen[1] = ret;
			else if (player == 2 && ret < chosen[1])
				chosen[1] = ret;
			ft_putnbr(ret);
			ft_putchar('\n');
		}
	}
	remove_coin(grid, x);
	return (chosen[1]);
}
