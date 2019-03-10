/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:12:48 by jcope             #+#    #+#             */
/*   Updated: 2019/03/07 21:17:06 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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
** Use malloc to make space for the map.
** Use malloc to make space for 2D map array.
** then you need to malloc out the rows of the map based on map_size as well,
** plus newline with strnew(). Set it all to .
*/

t_map	*new_map(int map_size)
{
	t_map	*map;
	int		i;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->array = (char**)ft_memalloc(sizeof(char*) * map_size);
	i = 0;
	while (i < map_size)
	{
		map->array[i] = ft_strnew(map_size);
		ft_memset(map->array[i], '.', map_size);
		i++;
	}
	return (map);
}

size_t	count_pieces(t_piece *piecelist)
{
	size_t	count;

	count = 0;
	while (piecelist)
	{
		piecelist = piecelist->next;
		count++;
	}
	return (count);
}

/*
** Print the map one row at a time followed by newline.
*/

void	print_map(t_map *map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

void	free_map(t_map *map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}
