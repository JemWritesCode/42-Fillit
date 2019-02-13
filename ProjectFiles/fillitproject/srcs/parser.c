/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:08:25 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/12 21:04:08 by cschulle         ###   ########.fr       */
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

int		charcount(int i, char buf[])
{
	int j;
	int count;

	j = 0;
	count = 0;
	while (j < i)
	{
		if (buf[j] == '.' || buf[j] == '#')
			count++;
		j++;
	}
	return (count);
}

t_piece		*piecemaker(char* start, char* end)
{
	t_piece *newpiece;
	int		i;

	while (start != end)
	{
		if (start[0] == '\n')
			start++;
	// make the data go into the thing		
		start++;
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
		piecelist = piecemaker(buf[i], buf[i+21]);
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
