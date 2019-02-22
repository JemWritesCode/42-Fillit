/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:12:48 by jcope             #+#    #+#             */
/*   Updated: 2019/02/17 19:12:49 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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

size_t	count_pieces(t_piece *piecelist)
{
	size_t	count;

	count = 0;
	while(piecelist != NULL)
	{
		piecelist = piecelist->next;
		count++;
	}
	return(count);
}

/*
* Print the map one row at a time followed by newline.
*/
void	print_map(t_map *map, int size)
{	
	int i;

	i = 0;
	while(i < size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

//void	free_map(t_map *map)
//{	
//}

//void	free_list(t_piece *piecelist)
//{	
//}
