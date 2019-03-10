/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:57:54 by jcope             #+#    #+#             */
/*   Updated: 2019/03/09 21:16:27 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Checks for any invalid characters
**	Checks for wrong-length lines ('\n' in an invalid position)
**	Counts number of '#' characters
**	Checks for '\n' at end of piece block
**	Returns false (0) if any checks are failed
*/

int		charcount(char *buf)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < 19)
	{
		if (buf[i] && buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		if (buf[i] == '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (!buf[i] || buf[i] != '\n')
		return (0);
	return (count);
}

/*
**	Checks each '#' character to see if it's adjacent to another
**	Returns a count of these adjacencies to validate piece shape
**	A valid piece with 4 '#' characters will either have 6 or 8 adjacencies
*/

int		adjacency_counter(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

/*
**	Iterates through buf 21 char (one piece chunk) at a time
**	Calls checking functions to confirm validity
**	Returns false (0) if any checks are failed
*/

int		valid(char *buf, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (charcount(buf + i) != 4)
			return (0);
		if (adjacency_counter(buf + i) != 6 && adjacency_counter(buf + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}
