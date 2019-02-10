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
	if (argc == 2)
		if(valid_file())
			//solve
	else
	{
		ft_putstr("usage: ./fillit source_file\n");
		EXIT_FAILURE;
	}
	return (0);
}