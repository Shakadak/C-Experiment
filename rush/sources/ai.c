#include "p4.h"
#include "libft.h"

static int		min(t_grid *grid, int depth);
static int		max(t_grid *grid, int depth);

int		minimax(t_grid *grid, int depth)
{
	int	chosen[3] =
	{
		-1, -1000, 0
	};
	int	ret;

	while (++chosen[0] < grid->x)
	{
		if (grid->grid[0][chosen[0]] != 0)
			continue ;
		if ((ret = put_coin(grid, chosen[0], 2)))
		{
			remove_coin(grid, chosen[0]);
			return (chosen[0]);
		}
		ret = min(grid, depth - 1);
		if (ret > chosen[1])
		{
			chosen[1] = ret;
			chosen[2] = chosen[0];
		}
		remove_coin(grid, chosen[0]);
	}
	return (chosen[2]);
}

int		min(t_grid *grid, int depth)
{
	int chosen[2] =
	{
		-1, 0
	};
	int	ret;

	while (++chosen[0] < grid->x)
	{
		if (grid->grid[0][chosen[0]] != 0)
			continue ;
		if (!(ret = heuristic(grid, chosen[0], 1)))
		{
			remove_coin(grid, chosen[0]);
			return (-1000);
		}
		if (depth)
			ret = max(grid, depth - 1);
		chosen[1] += ret;
		remove_coin(grid, chosen[0]);
	}
	return (chosen[1]);
}

int		max(t_grid *grid, int depth)
{
	int	chosen[2] =
	{
		-1, 0
	};
	int	ret;

	while (++chosen[0] < grid->x)
	{
		if (grid->grid[0][chosen[0]] != 0)
			continue ;
		if (!(ret = heuristic(grid, chosen[0], 2)))
		{
			remove_coin(grid, chosen[0]);
			return (1000);
		}
		if (depth)
			ret = min(grid, depth - 1);
		chosen[1] += ret;
		remove_coin(grid, chosen[0]);
	}
	return (chosen[1]);
}
