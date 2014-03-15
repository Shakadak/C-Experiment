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

int	heuristic(t_grid *grid, int row, char player)
{
	int		ret;

	ret = ai_put(grid, row, player);
	ret *= (player == 1 ? -1 : 1);
	return (ret);
}
