/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ply_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 15:33:19 by npineau           #+#    #+#             */
/*   Updated: 2014/03/09 17:52:55 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "p4.h"

int		get_first_ply(t_grid *grid);

int		*get_ply_order(t_grid *grid)
{
	int middle;
	int	*tab;
	int	i;
	int	j;

	i = 1;
	j = 1;
	middle = get_first_ply(grid);
	if ((tab = (int *)malloc(grid->x * sizeof(int))) == NULL)
		return (NULL);
	while (middle + i < (int)grid->x)
	{
		tab[j] = middle + i++;
		j += 2;
	}
	j = 0;
	while (middle >= 0)
	{
		tab[j] = middle--;
		j += 2;
	}
	return (tab);
}

int		get_first_ply(t_grid *grid)
{
	int	i;

	i = 0;
	while (i < (int)grid->x)
	{
		if (grid->grid[grid->y - 1][i] != 0)
			return (i);
		i++;
	}
	return (grid->x / 2 + 1);
}
