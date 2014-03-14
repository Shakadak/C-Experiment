/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:00:13 by npineau           #+#    #+#             */
/*   Updated: 2014/03/08 15:37:30 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "p4.h"

int		check_param(char **argv, t_grid *grid)
{
	char	*tmp;

	tmp = argv[1];
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			return (fatal("Invalide type of argument."));
		tmp++;
	}
	tmp = argv[2];
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			return (fatal("Invalide type of argument."));
		tmp++;
	}
	grid->x = ft_atoi(argv[1]);
	grid->y = ft_atoi(argv[2]);
	if (grid->x < 7 || grid->y < 6)
		return (fatal("Grid size under minima."));
	return (1);
}
