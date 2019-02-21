/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:08:25 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/20 19:42:11 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../libft/libft.h"

/*
**	WHAT THIS DOES
** 	- takes a string as argument (filename)
**	- opens file to produce file descriptor (fd)
**	- reads contents of file descriptor to malloc array size
**	- copies only relevant characters ('.' and '#') into a single string
**	- null-terminates string
**	- closes file
**	- returns string containing file contents
*/

void	align(t_piece piece)
{
	while (piece->blockcoords[0] != 0 && \
			piece->blockcoords[2] != 0 && \
			piece->blockcoords[4] != 0 && \
			piece->blockcoords[6] != 0)
		shift_x(piece, -1);
	while (piece->blockcoords[1] != 0 && \
			piece->blockcoords[3] != 0 && \
			piece->blockcoords[5] != 0 && \
			piece->blockcoords[7] != 0)
		shift_y(piece, -1);
}

t_piece		piecemaker(char* buf)
{
	t_piece newpiece;
	int	x;
	int y;
	int i;
	static char pieceletter;

	i = 0;
	x = 0;
	y = 1;
	pieceletter = 'A';
	while(i < 21)
	{
		if(buf[i] == '#')
		{
			newpiece->blockcoords[x] = (i > 5) ? (i % 5) : i;
			newpiece->blockcoords[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	newpiece->pieceletter = pieceletter;
	pieceletter++;
	align(newpiece);
	return (newpiece);
}

t_piece		*parser(char *filename)
{
	t_piece	*piecelist;
	char	buf[545]; // problem that this is uninitialized?
	int		fd;
	int		i;
	int		filesize;

	fd = open(filename, O_RDONLY);
	i = read(fd, buf, 545);
	if (i > 544 || i < 21)
		return (NULL);
	buf[i] = '\0';
	while (buf[i])
	{	
		//point the head of the thing at the head of the thing
		if(!(piecelist = piecemaker(buf[i])))
			return(NULL);
		i = i+21;
	}
}
