/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:49:18 by npineau           #+#    #+#             */
/*   Updated: 2014/03/14 17:16:50 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p4.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>

static int	get_entry(t_grid *grid);
static int	check_entry(char *src, t_grid *grid);

static void	display_winner(int winner)
{
	if (winner == 1)
		ft_putendl("You win. For now...");
	else if (winner == 2)
		ft_putendl("I win, as expected.");
	else
		ft_putendl("A draw ? Interesting.");
}

int			play(t_grid *grid)
{
	int		winner;
	int		player;
	int		coins;

	coins = grid->x * grid-> y;
	coins = coins % 2 ? coins - 1 : coins;
	srand(time(NULL));
	player = rand() % 2;
	winner = 0;
	while (coins && !winner)
	{
		if (player)
			winner = put_coin(grid, get_entry(grid), 1);
		else
			winner = put_coin(grid, minimax(grid, 0, 2), 2);
		player = (player ? 0 : 1);
		coins--;
	}
	display_grid(*grid);
	display_winner(winner);
	return (winner);
}

static int	get_entry(t_grid *grid)
{
	char	*prompt;
	int		column;

	column = -1;
	display_grid(*grid);
	while (column == -1)
	{
		ft_putendl("Human player, select wich column to put your coin in.");
		if (get_next_line(0, &prompt) == -1)
			return (fatal(strerror(errno)));
		column = check_entry(prompt, grid);
		ft_strdel(&prompt);
	}
	ft_strdel(&prompt);
	return (column);
}

static int	check_entry(char *src, t_grid *grid)
{
	int			nb;
	char		*tmp;

	tmp = src;
	if (*tmp == 0)
		return (-1);
	while (*tmp)
	{
		if (!ft_isdigit(*tmp++))
			return (-1);
	}
	nb = ft_atoi(src);
	if (nb < 0 || nb >= (int)grid->x)
		return (-1);
	else if (grid->grid[0][nb])
		return (-1);
	return (nb);
}
