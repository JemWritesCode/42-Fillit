/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:57:54 by jcope             #+#    #+#             */
/*   Updated: 2019/02/24 23:27:41 by cschulle         ###   ########.fr       */
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

#include <stdio.h>

int		charcount(char* buf)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while(i < 20)
	{
		if(buf[i] != '\n' && buf[i] != '#' && buf[i] != '.') // checks for invalid chars
			printf("invalid char at %d\n", i); //TODO: fix for files with no newline at end
			//return(0);
		if(buf[i] == '\n' && !(((i + 1) % 5) == 0)) // checks for newlines in the wrong places/line length
			printf("misplaced newline at %d\n", i); 
			//return(0);
		if(buf[i] == '#')
			count++;
		i++;
	}
	if(buf[i] && buf[i] != '\n') // checks block length
		printf("invalid block length i = %d\n", i); 
		//return(0);
	return(count); // returns number of '#' characters contained in string
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

int		valid(char *buf, int size)
{
	int i;

	i = 0;
	while(i <= size)
	{
		if(charcount(buf + i) != 4)
			return(0);
		if(adjacency_counter(buf + i) != 6 && adjacency_counter(buf + i) != 8)
			return(0);
		i += 21;
	}
	return(1);
}
