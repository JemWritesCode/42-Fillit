/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:57:54 by jcope             #+#    #+#             */
/*   Updated: 2019/02/16 23:13:12 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	WHAT THIS DOES
**	Checks the following conditions to ensure the given piece-block is valid:
**	- Contains 4 and only 4 '#' characters
**	- lines are exactly 4 chars long (excluding newlines)
**	- Piece block is exactly 4 lines long
**	- Doesn't contain any invalid characters
**	- contains a valid number of adjacencies
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
	int i;
	int count;

	i = 0;
	count = 0;
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

#include <stdio.h>

int main(void)
{
	char *buf1 = "....\n....\n....\n####\n\n"; // valid 
	char *buf2 = "...\n....\n....\n####\n\n"; // line too short
	char *buf3 = "...\n....\n....\n####\n....\n\n"; // block too long
	char *buf4 = "...\n....\n....\n#A##\n\n"; // invalid character
	char *buf5 = "....\n....\n....\n#.##\n\n"; // invalid tetromino
	//char *buf6 = ""; // empty buf
	if (charcount(buf1) == 4)
		printf("charcount works on valid input :)\n");
	else
		printf("charcount broke :(\n");

	if (adjacency_counter(buf1) == 6 || adjacency_counter(buf1) == 8)
		printf("adjacency counter works on valid input :)\n");
	else
		printf("adjacency counter broke :(\n");
	
	if (charcount(buf2) != 4)
		printf("charcount detects line too short :)\n");
	else
		printf("charcount broke :(\n");

	if (charcount(buf3) != 4)
		printf("charcount detects block too long :)\n");
	else
		printf("charcount broke :(\n");

	if (charcount(buf4) != 4)
		printf("charcount detects invalid character :)\n");
	else
		printf("charcount broke :(\n");

	if (adjacency_counter(buf5) != 6 && adjacency_counter(buf5) != 8)
		printf("adjacency counter detects invalid piece :)\n");
	else
		printf("adjacency counter broke :(\n");
	return (0);
}
