/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validitychecker_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:31:20 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/17 19:32:08 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
char *buf1 = "....\n....\n....\n####\n\n"; // valid
	char *buf2 = "...\n....\n....\n####\n\n"; // line too short
	char *buf3 = "...\n....\n....\n####\n....\n\n"; // block too long
	char *buf4 = "...\n....\n....\n#A##\n\n"; // invalid character
	char *buf5 = "....\n....\n....\n#.##\n\n"; // invalid tetromino
	
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
