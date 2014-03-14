/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 17:10:35 by npineau           #+#    #+#             */
/*   Updated: 2014/03/09 22:48:39 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "p4.h"

/*
static int	*int_array_dup(int *row, int size)
{
	int	i;
	int	*new;

	if (!(new = (int *)malloc(size * sizeof(int))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = row[i];
		i++;
	}
	return (new);
}
*/

t_tree		**new_litter(int size, char player, int *row)
{
	t_tree	**new;
	int	x;

	x = size;
	if (!(new = (t_tree **)malloc(size * sizeof(t_tree *))))
		return (NULL);
	while (--x >= 0)
	{
		new[x] = new_node(row, x, player);
	}
	return (new);
}

t_tree		*new_node(int *row, int x, char player)
{
	t_tree	*new;

	if (!(new = (t_tree *)malloc(sizeof(t_tree))))
		return (NULL);
	new->x = x;
	new->player = player;
	new->land = row;
	new->weight = 5;
	new->children = NULL;
	return (new);
}
