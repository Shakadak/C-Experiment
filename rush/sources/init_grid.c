/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:51:39 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/14 13:17:06 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "p4.h"
#include "libft.h"

int		init_grid(t_grid *grid)
{
	int	i;

	i = 0;
	if (!(grid->grid = (char **)malloc(grid->y * sizeof(char *))))
		return (fatal(strerror(errno)));
	while (i < grid->y)
	{
		if (!(grid->grid[i] = ft_strnew(grid->x - 1)))
			return (fatal(strerror(errno)));
		i++;
	}
	return (0);
}
