/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:26:47 by jcope             #+#    #+#             */
/*   Updated: 2019/02/06 17:26:48 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	t_piece	*piecelist;
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		EXIT_FAILURE;
	}
	if((piecelist = parser(argv[1])) == NULL)
	{
		ft_putstr("error\n");
		EXIT_FAILURE;		
	}
	map = solve(piecelist);
	//free_map(map);
	//free_list(piecelist);
	return (0);
}