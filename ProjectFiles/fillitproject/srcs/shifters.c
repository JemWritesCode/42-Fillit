/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:39:43 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/21 20:19:46 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*	
**	Shifts a piece 'n' places along the x-axis
*/

void	shift_x(t_piece *piece, int n)
{
	piece->blockcoords[0] += n;
	piece->blockcoords[2] += n;
	piece->blockcoords[4] += n;
	piece->blockcoords[6] += n;
}

/*	
**	Shifts a piece 'n' places along the y-axis
*/

void	shift_y(t_piece *piece, int n)
{
	piece->blockcoords[1] += n;
	piece->blockcoords[3] += n;
	piece->blockcoords[5] += n;
	piece->blockcoords[7] += n;
}
