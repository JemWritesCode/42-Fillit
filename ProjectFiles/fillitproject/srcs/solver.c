/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:38:59 by jcope             #+#    #+#             */
/*   Updated: 2019/02/15 19:39:00 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		overlap(t_map *map, t_piece *piece)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	x = piece->blockcoords[i] + piece->x_offset;
	y = piece->blockcoords[i + 1] + piece->y_offset;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i += 2;
		x = piece->blockcoords[i] + piece->x_offset;
		y = piece->blockcoords[i + 1] + piece->y_offset;
	}
	return (i != 8);
}

void	place(t_piece *piece, t_map *map, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = piece->blockcoords[i] + piece->x_offset;
		y = piece->blockcoords[i + 1] + piece->y_offset;
		map->array[y][x] = letter;
		i += 2;
	}
}

int		in_bounds(t_piece *piece, int map_size, char axis)
{
	if (axis == 'y')
		return (piece->blockcoords[1] + piece->y_offset < map_size &&
				piece->blockcoords[3] + piece->y_offset < map_size &&
				piece->blockcoords[5] + piece->y_offset < map_size &&
				piece->blockcoords[7] + piece->y_offset < map_size);
	else
		return (piece->blockcoords[0] + piece->x_offset < map_size &&
				piece->blockcoords[2] + piece->x_offset < map_size &&
				piece->blockcoords[4] + piece->x_offset < map_size &&
				piece->blockcoords[6] + piece->x_offset < map_size);
}

/*
** While in bounds, if it doesn't overlap place the piece. Use recursion
** to check if the rest can fit with the current piece placed where it is.
**  Otherwise it backtracks and moves current piece
** then checks if all the pieces that come after fit with current piece moved.
*/

int		solve_map(t_map *map, t_piece *piece, int map_size)
{
	if (!piece)
		return (1);
	piece->x_offset = 0;
	piece->y_offset = 0;
	while (in_bounds(piece, map_size, 'y'))
	{
		while (in_bounds(piece, map_size, 'x'))
		{
			if (!overlap(map, piece))
			{
				place(piece, map, piece->pieceletter);
				if (solve_map(map, piece->next, map_size))
					return (1);
				else
				{
					place(piece, map, '.');
				}
			}
			piece->x_offset++;
		}
		piece->x_offset = 0;
		piece->y_offset++;
	}
	return (0);
}

/*
** Get the square root and round it up for starting map map_size.
** Example: If the number of blocks in pieces would require a 2.3 x 2.3 grid
** then it needs to round up to be 3x3 minimum to fit.
** In that case this function would return 3.
*/

int		round_up_sq_rt(int num)
{
	int	map_size;

	map_size = 2;
	while (map_size * map_size < num)
		map_size++;
	return (map_size);
}

/*
** Start with the smallest map map_size for number of blocks in pieces.
*/

t_map	*solve(t_piece *piecelist)
{
	t_map	*map;
	int		map_size;

	map_size = round_up_sq_rt(count_pieces(piecelist) * 4);
	map = new_map(map_size);
	while (!solve_map(map, piecelist, map_size))
	{
		map_size++;
		//free_map(map);
		map = new_map(map_size);
	}
	print_map(map, map_size);
	return (map);
}
