/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:51:38 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/14 13:35:05 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "p4.h"
#include "libft.h"

void		display_grid_up(int i)
{
	int	j;
	int	spaces;

	j = 0;
	write(1, "\t\033[32m", 6);
	write(1, "\033[1m", 4);
	write(1, "\033[2C", 4);
	while (j < i)
	{
		ft_putnbr(j);
		spaces = j / 10 >= 1 ? 2 : 3;
		while (spaces-- > 0)
			write(1, " ", 1);
		j++;
	}
	write(1, "\n\t\033[34m", 7);
	WRITE_GRAPH_MOD;
	write (1, "lq", 2);
	while (i-- > 1)
		write (1, " qwq", 4);
	write (1, " qk", 3);
	write(1, "\033(B\n", 4);
}

void		display_grid_mid(int i)
{
	write(1, "\t\033[34m", 6);
	WRITE_GRAPH_MOD;
	write(1, "tq", 2);
	while (i-- > 1)
		write (1, "qqnq", 4);
	write(1, "qqu", 3);
	write(1, "\033(B\n", 4);
}

void		display_grid_down(int i)
{
	write(1, "\t\033[34m", 6);
	WRITE_GRAPH_MOD;
	write(1, "mq", 2);
	while (i-- > 1)
		write (1, "qqvq", 4);
	write(1, "qqj", 3);
	write(1, "\033(B\n", 4);
}

void		display_grid_pieces(int num, int len, char *line)
{
	int			j;
	static char	colors[3][22] =
	{
		"\033(0x\033(B\033[34m . ",
		"\033(0x\033(B\033[31m ◉ \033[34m",
		"\033(0x\033(B\033[33m ◉ \033[34m"
	};

	j = 0;
	write(1, "\033[32m   ", 8);
	ft_putnbr(num);
	write(1, "\t\033[34m", 6);
	while (j < len)
	{
		write(1, colors[(int)line[j]], 22);
		j++;
	}
	write(1, "\033(0x\n\033(B", 8);
}

void		display_grid(t_grid g)
{
	int	i;

	write(1, "\033[2J\033[0;0H", 10);
	i = 0;
	display_grid_up(g.x);
	while (i < g.y * 2 - 1)
	{
		if (i % 2 == 0)
			display_grid_pieces(i / 2, g.x, g.grid[i / 2]);
		else
			display_grid_mid(g.x);
		i++;
	}
	display_grid_down(g.x);
}
