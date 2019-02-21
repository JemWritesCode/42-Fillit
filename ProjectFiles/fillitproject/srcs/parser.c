/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:08:25 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/20 16:44:32 by cschulle         ###   ########.fr       */
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

void	shift_x(int coords[8], int n)
{
	coords[0] += n;
	coords[2] += n;
	coords[4] += n;
	coords[6] += n;
}


void	shift_y(int coords[8], int n)
{
	coords[1] += n;
	coords[3] += n;
	coords[5] += n;
	coords[7] += n;
}

char	*findcorner(char* buf)
{
	int		i;
	char	*corner;

	i = 0;
	while (buf[i] == '.' || buf[i] == '\n')
		i++;
	while (buf[i + 4] == '#' || buf
	corner = buf + i;
	return (corner);
}

int		**piecemapper(char* buf)
{
	int **piecemap;
	int i;
	int point;
	i = 0;
	point = 0;
	while(i < 20)
	{
		if(buf[i] == '#')
		{
			piecemap[point][0] = ; //math
			piecemap[point][1] = ; //math
			point++;
		}
		i++;
	}
	return(piecemap);
}

t_piece		*piecemaker(char* buf)
{
	t_piece *newpiece;
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

			x += 2;
			y += 2;
		}
	
		i++;
	}
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

/*
	filesize = charcount(i, buf);
	if (!(filecontents = malloc((size_t)filesize + 1)))		// be sure to free after use in calling function!
		return (NULL);
	filecontents[filesize] = '\0';
	filesize--;
	while (filesize >= 0)
	{
		if (buf[i] == '.' || buf[i] == '#')
		{
			filecontents[filesize] = buf[i];
			filesize--;
		}
		i--;
	}
*/	close(fd);
	return (piecelist);
}
