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
