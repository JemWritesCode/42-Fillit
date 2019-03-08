/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:23:06 by cschulle          #+#    #+#             */
/*   Updated: 2019/03/07 20:47:01 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
/*
void	free_piecelist(t_piece *piecelist)
{	
	while (piecelist)
	{
		// need to delete the stuff from inside of the piecelist?
		ft_memdel((void **)&piecelist); // this deletes the overall piecelist
		piecelist = piecelist->next;
	}
	return (NULL);	
}
*/
void	align(t_piece *piece)
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

t_piece		*makepiece(char *buf, char pieceletter)
{
	t_piece	*piece_ptr;
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 1;
	if (!(piece_ptr = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			piece_ptr->blockcoords[x] = (i >= 5) ? (i % 5) : i;
			piece_ptr->blockcoords[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	piece_ptr->x_offset = 0;
	piece_ptr->y_offset = 0;
	piece_ptr->pieceletter = pieceletter;
	align(piece_ptr);
	return (piece_ptr);
}

t_piece		*makelist(char *buf, int size)
{
	t_piece *current;
	t_piece *beginning;
	int 	i;
	char	pieceletter;

	i = 0;
	pieceletter = 'A';
	while (i < size)
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
		i += 21;
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
	if (bytecount > 544 || bytecount < 19)
		return (NULL);
	buf[bytecount] = '\0';
	if (!valid(buf, bytecount))
		return (NULL);
	return (makelist(buf, bytecount));
}
