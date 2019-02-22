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
#include <stdio.h> // For Testing, remove this!

int		check_overlap(t_map *map, t_piece *piece)
{
	int	avail;
	int x;
	int y;
	

	x = 0;
	y = 1;
	avail = 0;
	
	while(x <= 6 && map->array[piece->blockcoords[y]][piece->blockcoords[x]] == '.')
	{
		printf("x: %d, y: %d\n", piece->blockcoords[x], piece->blockcoords[y]);
		printf("%s\n", "Space Avail");
		avail++;
		x += 2;
		y += 2;

	}
	printf("avail: %d\n", avail);
	return (avail == 4);
}

void	place(t_piece *piece, t_map *map)
{
	int x;
	int y;
	

	x = 0;
	y = 1;
	while(x <= 6)
	{
		
		map->array[piece->blockcoords[y]][piece->blockcoords[x]] = piece->pieceletter;
		x += 2;
		y += 2;		
	}
	printf("\n");

}



int		solve_map(t_map *map, t_piece *piece, int map_size)
{


	printf("Map Size:%d\n", map_size);

	while(piece)
	{
		if (check_overlap(map, piece))
		{
			place(piece, map);
		}
		piece = piece->next;
	}
	return (0); //solved
}

/*
* Get the square root and round it up for starting map map_size.
* Example: If the number of blocks in pieces would require a 2.3 x 2.3 grid
* then it needs to round up to be 3x3 minimum to fit.
* In that case this function would return 3.
*/

int		round_up_sq_rt(int num)
{
	int	map_size;

	map_size = 2;
	while (map_size * map_size < num)
		map_size++;
	return(map_size);
}

/*
* Start with the smallest map map_size for number of blocks in pieces.
*/

t_map	*solve(t_piece *piecelist)
{
	t_map	*map;
	int		map_size;

	map_size = round_up_sq_rt(count_pieces(piecelist) * 4);
	map = new_map(map_size);

	solve_map(map, piecelist, map_size);
	//print_map(map, map_size);
	return(map);
}
