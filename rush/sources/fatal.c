/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:09:39 by npineau           #+#    #+#             */
/*   Updated: 2014/03/09 11:33:45 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Can be used as fatal("random comment") or fatal(strerror(errno)).
*/

int	fatal(char *disambiguation)
{
	ft_putstr_fd("puissance4: ", 2);
	ft_putendl_fd(disambiguation, 2);
	return (-1);
}
