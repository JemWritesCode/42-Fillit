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

void	place(t_map *map, int x, int y, char letter)
{
	map->array[x][y] = letter;
}



int		solve_map(t_map *map, t_piece *piecelist, int map_size)
{
	int x;
	int y;

	x = 0;
	y = 1;

	if (map->array[piecelist->blockcoords[x]][piecelist->blockcoords[y]] == '.')
		printf("%s\n", "Space Avail");
	
	printf("Map Size:%d\n", map_size);
	

	//to get to the next set of cords x += 2 / y += 2
	return (0); //solved
}



t_map	*new_map(int map_size)
{
	t_map *map;
	int i;

	map = (t_map *)ft_memalloc(sizeof(t_map)); //malloc a map the map_size of map struct.

	// map_size of map * char pointer. 
	//Turn this into ** so it's basically like the first column of the map.
	map->array = (char**)ft_memalloc(sizeof(char*) * map_size); 
	//then you need to malloc out the rows of the map based on map_size as well, plus newline.
	i = 0;
	while (i < map_size)
	{
		map->array[i] = ft_strnew(map_size); 
		ft_memset(map->array[i], '.', map_size); // fill in each row with .
		i++; // go to the next row. 
	}
	return (map);
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

	//solve_map(map, piecelist, map_size);
	//print_map(map, map_size);
	return(map);
}
