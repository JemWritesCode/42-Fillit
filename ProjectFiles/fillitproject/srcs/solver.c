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

//int		solve_map(t_map *map, t_list *list, int size)
//{
//
//}

t_map	*new_map(int size)
{
	t_map *map;
	int i;

	map = (t_map *)ft_memalloc(sizeof(t_map)); //malloc a map the size of map struct.

	// size of map * char pointer. 
	//Turn this into ** so it's basically like the first column of the map.
	map->array = (char**)ft_memalloc(sizeof(char*) * size); 
	//then you need to malloc out the rows of the map based on size as well, plus newline.
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size); 
		ft_memset(&map->array[i], '.', size); // fill in each row with .
		i++; // go to the next row. 
	}
	return (map);
}

/*
* Get the square root and round it up for starting map size.
* Example: If the number of blocks in pieces would require a 2.3 x 2.3 grid
* then it needs to round up to be 3x3 minimum to fit.
* In that case this function would return 3.
*/

int		round_up_sq_rt(int num)
{
	int	size;

	size = 2;
	while (size * size < num)
		size++;
	return(size);
}

/*
* Start with the smallest map size for number of blocks in pieces.
*/

t_map	*solve(t_piece *piecelist)
{
	t_map	*map;
	int		size;

	size = round_up_sq_rt(count_pieces(piecelist) * 4);
	map = new_map(size);
	//solve_map(map, piecelist, size);
	//print_map(map, size);
	return(map);
}
