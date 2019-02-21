/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fakepiecelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:56:03 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/21 10:53:30 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ProjectFiles/fillitproject/includes/fillit.h"

int	main(void)
{
	t_piece first = {{0, 0, 0, 1, 1, 0, 1, 1}, 'A', NULL};
	t_piece second = {{0, 0, 0, 1, 1, 0, 1, 1}, 'B', NULL};
	t_piece third = {{0, 0, 0, 1, 1, 0, 1, 1}, 'C', NULL};
	first.next = &second;
	second.next = &third;
	t_piece *listhead = &first;

	return (0);
}
