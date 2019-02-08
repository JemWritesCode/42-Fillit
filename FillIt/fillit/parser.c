/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:08:25 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/07 21:25:40 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

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

char	*parser(char *filename)
{
	char	*filecontents;
	char	buf[167];
	int		fd;
	int		i[2];
	int		filesize;

	i[0] = 0;
	i[1] = -1;
	fd = open(filename, O_RDONLY);
	filesize = read(fd, buf, 167);
	filecontents = malloc((size_t)filesize - (filesize % 16)); 		// be sure to free after use in calling function!
	while (i[0] < filesize)
	{
		if (buf[i[0]] == '.' || buf[i[0]] == '#')
			filecontents[++(i[1])] = buf[i[0]];
		(i[0])++;
	}
	filecontents[(i[1]) + 2] = '\0';
	close(fd);
	return (filecontents);
}
