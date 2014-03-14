/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:36:39 by npineau           #+#    #+#             */
/*   Updated: 2014/03/09 11:16:55 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "p4.h"

int	main(int argc, char **argv)
{
	t_grid	grid;

	if (argc != 3)
		return (fatal("Usage: ./puissance4 width height"));
	if (check_param(argv, &grid) == -1)
		return (-1);
	if ((init_grid(&grid)) == -1)
		return (-1);
	play(&grid);
	free_grid(&grid);
	return (0);
}
