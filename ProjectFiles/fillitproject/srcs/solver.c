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

t_map	*new_map(int size)
{
	t_map *map;

	map = (*t_map)ft_memalloc(sizeof(t_map)); //malloc a map the size of map struct.
	map->size = size;
	map->array = 

}

/*
* Get the square root and round it up for starting map size.
* Example: If the number of blocks in pieces would require a 2.3 x 2.3 grid
* then it needs to round up to be 3x3 minimum to fit.
*/

int		round_up_sq_rt(int num)
{
	int	size;

	size = 2;
	while (size * size < n)
		size++;
	return(size);
}

/*
* Start with the smallest map size for # of blocks in pieces.
*/

t_map	*solve(t_piece *piecelist)
{
	t_map	*map;
	int		size;

	size = round_up_sq_rt(ft_lstcount(piecelist) * 4);
	map = new_map(size);

}