/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 11:08:26 by npineau           #+#    #+#             */
/*   Updated: 2014/03/14 13:18:02 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "p4.h"

void	free_grid(t_grid *grid)
{
	int	i;

	i = 0;
	while (i < grid->y)
		free(grid->grid[i++]);
	free(grid->grid);
	grid->grid = NULL;
}
