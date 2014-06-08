/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OR.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 16:39:37 by npineau           #+#    #+#             */
/*   Updated: 2014/06/08 18:15:43 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define NONE	0
#define UP		1
#define DOWN	(1 << 1)
#define LEFT	(1 << 2)
#define RIGHT	(1 << 3)

int		test(int flag)
{
	if (flag & UP)
		printf("UP\n");
	if (flag & DOWN)
		printf("DOWN\n");
	if (flag & LEFT)
		printf("LEFT\n");
	if (flag & RIGHT)
		printf("RIGHT\n");/*
	if (flag == (LEFT | UP))
		printf("LEFT | UP\n");
	if (flag == (RIGHT | UP))
		printf("RIGHT | UP\n");
	if (flag == (LEFT | DOWN))
		printf("LEFT | DOWN\n");
	if (flag == (RIGHT | DOWN))
		printf("RIGHT | DOWN\n");*/
	printf("%d\n-----\n", flag);
	return (flag);
}

int		main(void)
{
	int	flag;

	test(test(test(test(test(UP) | LEFT) ^ LEFT) ^ UP | RIGHT) ^ RIGHT | DOWN);
	return (0);
}
