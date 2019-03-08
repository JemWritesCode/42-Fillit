/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:37:27 by cschulle          #+#    #+#             */
/*   Updated: 2019/03/07 20:02:51 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	free_piecelist(t_piece *list)
{
	t_piece *tmp;
	while(list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
/*
void	free_map(t_map *map)
{
	int i;

	i = 0;
	while(map->array[i])
	{
		free(map->array[i]);
		i++;
	}
	free(map->array);
}*/
