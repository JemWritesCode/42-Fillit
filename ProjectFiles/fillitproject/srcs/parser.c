/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:08:25 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/15 13:01:33 by cschulle         ###   ########.fr       */
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

int		charcount(char* buf)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if(buf[20] != '\n') // checks block length
		return(0);
	while(i < 21)
	{
		if(buf[i] != '\n' && buf[i] != '#' && buf[i] != '.') // checks for invalid chars
			return(0);
		if(buf[i] == '\n' && !(i == 20 || ((i + 1) % 5) == 0)) // checks for newlines in the wrong places/line length
			return(0);
		if(buf[i] == '#')
			count++;
		i++;
	}
	return(count); // returns number of '#' characters containted in string
}

int		adjacency_counter(char* buf)
{
	if (charcount(buf) != 4)
		return (0);
	while(i < 21)
	{
		if(buf[i] == '#')
		{
			if(i + 1 <= 18 && buf[i + 1] == '#')
				count++;
			if(i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if(i + 5 <= 18 && buf[i + 5] == '#')
				count++;
			if(i - 5 >= 0 && buf[i - 5] == '#')
				count++;
		}
		i++;
	}
	return(count);
}

int		*dimensions(char* buf)
{

	return(dim);
}

t_piece		*piecemaker(char* buf)
{
	t_piece *newpiece;
	int		i;
	int		x;
	int		y;

	while(i < 21)
	{
		if (
		if (buf[i] != '#')
			i++;
		else (buf[i] == '#')
			hash++;
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
