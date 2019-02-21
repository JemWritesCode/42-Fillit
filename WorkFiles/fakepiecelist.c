/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fakepiecelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:56:03 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/20 21:03:53 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ProjectFiles/fillitproject/includes/fillit.h"

int	main(void)
{
	t_piece first;
	t_piece second;
	t_piece third;

	first->blockcoords = {0, 0, 0, 1, 0, 2, 0, 3};
	first->pieceletter = A;
	first->next = second;

	second->blockcoords = {0, 0, 1, 0, 0, 1, 1, 1};
	second->pieceletter = B;
	second->next = third;

	third->blockcoords = {1, 0, 1, 1, 1, 2, 0, 2};
	third->pieceletter = C;
	third->next = NULL;
}
