/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:22:08 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/14 13:16:45 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P4_H
# define P4_H

# define MAXDEPTH			8
# define WRITE_TEXT_MOD		write(1, "\033(B", 3)
# define WRITE_GRAPH_MOD	write(1, "\033(0", 3)

typedef struct		s_grid
{
	int				x;
	int				y;
	char			**grid;
}					t_grid;

typedef struct		s_tree
{
	int			x;
	int			*land;
	char			player;
	char			weight;
	struct s_tree	**children;
}					t_tree;

int		fatal(char *disambiguation);
int		check_param(char **argv, t_grid *grid);
int		init_grid(t_grid *grid);
void	display_grid(t_grid g);
int		play(t_grid *grid);
int		put_coin(t_grid *grid, int col, char p);
void	remove_coin(t_grid *grid, int col);
int		check_four(t_grid *grid, int row, int col);
void	free_grid(t_grid *grid);
int		dup_grid(t_grid *src, t_grid *dest);
int		ai_ply(t_grid *grid);
int		*get_ply_order(t_grid *grid);
int		ai_put(t_grid *grid, int col, char player);
void	ai_remove_coin(t_tree *node, t_grid *grid);
t_tree	*new_node(int *row, int x, char player);
int		ai_ply(t_grid *g);
int		ai_move(t_grid *grid, int depth);
t_tree	**new_litter(int size, char player, int *row);

int		minimax(t_grid *grid, int depth);
int		heuristic(t_grid *grid, int row, char player);

int		check_vertical(t_grid *grid, int row, int col);
int		check_horizontal(t_grid *grid, int row, int col);
int		check_diagonal_up(t_grid *grid, int row, int col);
int		check_diagonal_down(t_grid *grid, int row, int col);

#endif /* !P4_H */
