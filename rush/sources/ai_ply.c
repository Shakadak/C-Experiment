/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_ply.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 14:38:48 by npineau           #+#    #+#             */
/*   Updated: 2014/03/09 23:29:07 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "p4.h"

#include <stdio.h> ////
#include <unistd.h>

static int		*init_landscape(t_grid *g)
{
	int	x;
	int	*tab;
	int	count;

	tab = (int *)malloc(g->x * sizeof(int));
	x = 0;
	while (x < (int)g->x)
	{
		count = g->y;
		while (--count >= 0 && g->grid[count][x])
			 ;
		tab[x] = count;
		x++;
	}
	return (tab);
}

static void	ai_test_coin(t_grid *g, t_tree *t)
{
	int	check;

	if (t->land[t->x] == -1)
	{
		printf("TEST COIN\n");
		t->x = -1;
		return ;
	}
	printf("PLAYER = %d\n", t->player);
	usleep(500);
	check = ai_put_coin(t, g);
	display_grid(*g);
	if (t->player == check)
		t->weight = t->player == 1 ? 0 : 10;
	t->children = new_litter(g->x, t->player % 2 + 1, t->land);
	ai_remove_coin(t, g);
}

static int		ai_check_depth(int depth, int currdepth, t_tree *t, t_grid *g)
{
	int	i;

	i = 0;
	if (depth == currdepth)
	{
		printf("d:%d, cd:%d x:%d CURR = DEP\n", depth, currdepth, t->x);
		ai_test_coin(g, t);
	}
	else
	{
		if (!t)
			return (0);
		ai_put_coin(t, g);
		while (i < (int)g->x)
		{
			ai_check_depth(depth, currdepth + 1, t->children[i], g);
			if (t->children[i]->x == -1)
				continue ;
			else if (t->player == 1 && t->children[i]->weight < t->weight)
				t->weight = t->children[i]->weight;
			else if (t->player == 2 && t->children[i]->weight > t->weight)
				t->weight = t->children[i]->weight;
			i++;
		}
		ai_remove_coin(t, g);
	}
	return (0);
}

int			ai_ply(t_grid *grid)
{
	static int	*ply_order = NULL;
	t_tree		*head;
	int		i;
	int		bestx;
	int		bestweight;

	i = 1;
	bestweight = 0;
	bestx = 0;
	if (!ply_order)
		ply_order = get_ply_order(grid);
	head = new_node(init_landscape(grid), 0, 1);
	head->children = new_litter(grid->x, 2, head->land);
	printf("%p %d\n", head->children[i], head->children[i]->x);
	while (i <= MAXDEPTH)
		ai_check_depth(i++, 0, head, grid);
	i = 0;
	while (i < (int)grid->x)
	{
		if (head->children[ply_order[i]]->weight > bestx)
		{
			bestx = head->children[i]->x;
			bestweight = head->children[i]->weight;
		}
		i++;
	}
//	free_tree(head);
	return (put_coin(grid, bestx, 2));
}
