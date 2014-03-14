/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 14:28:53 by npineau           #+#    #+#             */
/*   Updated: 2014/03/09 14:44:44 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "p4.h"

int		dup_grid(t_grid *src, t_grid *dest)
{
	unsigned int	i;

	i = 0;
	dest->x = src->x;
	dest->y = src->y;
	if ((dest->grid = (char **)malloc(dest->y * sizeof(char *))) == NULL)
		return (fatal(strerror(errno)));
	while (i < dest->y)
		dest->grid[i] = ft_strdup(src->grid[i]);
	return (1);
}
