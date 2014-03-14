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

int		ai_put_coin(t_tree *node, t_grid *grid)
{
	grid->grid[node->land[node->x]][node->x] = node->player;
	node->land[node->x] -= 1;
	return (check_four(grid, node->land[node->x] + 1, node->x));
}

void	ai_remove_coin(t_tree *node, t_grid *grid)
{
	node->land[node->x] += 1;
	grid->grid[node->land[node->x]][node->x] = 0;
}
