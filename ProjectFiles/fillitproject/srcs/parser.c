/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:08:25 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/21 17:15:37 by cschulle         ###   ########.fr       */
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

t_piece		makepiece(char* buf, char pieceletter)
{
	t_piece newpiece;
	int	x;
	int y;
	int i;

	i = 0;
	x = 0;
	y = 1;
	while(i < 21)
	{
		if(buf[i] == '#')
		{
			newpiece.blockcoords[x] = (i > 5) ? (i % 5) : i;
			newpiece.blockcoords[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	newpiece.pieceletter = pieceletter;
	//align(newpiece);
	return (newpiece);
}

t_piece		*makelist(char *buf) // too many lines -- may be best to edit validity checker to work on entire file instead of chunks, to be called in parser -- would save 5 lines
{
	t_piece *current;
	t_piece *beginning;
	int 	i;
	char	pieceletter;

	i = 0;
	pieceletter = 'A';
	while (buf[i])
	{	
		if (valid(buf + i))
		{
			if (pieceletter == 'A')
			{
				beginning = makepiece(buf + i, pieceletter);
				current = beginning;
			}
			else
			{
				current->next = makepiece(buf + i, pieceletter);
				current = current->next;
			}
			pieceletter++;
		}
		else
			return (NULL);
		i = i+21;
	}
	return (beginning);
}

t_piece		*parser(char *filename)
{
	char	buf[545];
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buf, 545);
	if (bytecount > 544 || bytecount < 21)
		return (NULL);
	buf[bytecount] = '\0';
	return (makelist(buf));
}
