/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validitychecker_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:31:20 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/26 18:16:08 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define GREEN "\e[38;5;83m"
#define RED "\e[38;5;160m"
#define GREY "\e[38;5;241m"
#define ENDCOLOR "\e[0m"

int		charcount(char* buf);
int		adjacency_counter(char* buf);
int		valid(char* buf, int size);

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*readfile(char *filename) // reads the file in for testing -- same functionality as parser()
{
	char	buf[545];
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buf, 545);
	char* ret = malloc(bytecount + 1);
	if (bytecount <= 0)
		return (NULL);
	if (bytecount > 544 || bytecount < 20)
		return (NULL);
	int i = 0;
	while (i < bytecount)
	{
		ret[i] = buf[i];
		i++;
	}
	ret[bytecount] = '\0';
	return (ret);
}

int main(void)
{

/* valid() tests */
	printf("valid() tests\n");

	char *filepath;
	int valid_expected;	
	char *testbuf;
	int size;
	int valid_return;

	filepath = "../TestFiles/valid_1";
	valid_expected = 1;
	testbuf = readfile(filepath);
	size = ft_strlen(testbuf);
	valid_return = valid(testbuf, size);
	printf(GREY"%s "ENDCOLOR, filepath);
	if (valid_return == valid_expected)
		printf(GREEN"%d\n"ENDCOLOR, valid_return);
	else
		printf(RED"%d\n"ENDCOLOR, valid_return);

	filepath = "../TestFiles/valid_4";
	valid_expected = 1;
	testbuf = readfile(filepath);
	size = ft_strlen(testbuf);
	valid_return = valid(testbuf, size);
	printf(GREY"%s "ENDCOLOR, filepath);
	if (valid_return == valid_expected)
		printf(GREEN"%d\n"ENDCOLOR, valid_return);
	else
		printf(RED"%d\n"ENDCOLOR, valid_return);

	filepath = "../TestFiles/26Pieces";
	valid_expected = 1;
	testbuf = readfile(filepath);
	size = ft_strlen(testbuf);
	valid_return = valid(testbuf, size);
	printf(GREY"%s "ENDCOLOR, filepath);
	if (valid_return == valid_expected)
		printf(GREEN"%d\n"ENDCOLOR, valid_return);
	else
		printf(RED"%d\n"ENDCOLOR, valid_return);

	filepath = "../TestFiles/invalid_sample";
	valid_expected = 0;
	printf(GREY"%s "ENDCOLOR, filepath);
	size = ft_strlen(testbuf);
	valid_return = valid(testbuf, size);
	if (valid_return == valid_expected)
		printf(GREEN"%d\n"ENDCOLOR, valid_return);
	else
		printf(RED"%d\n"ENDCOLOR, valid_return);

/* charcount() tests */
	printf("\ncharcount() tests\n");

	char *test_string;
	int charcount_return;
	int	charcount_expected;
	
	test_string = "....\n.##.\n.##.\n....\n"; // valid piece
	charcount_expected = 4;
	charcount_return = charcount(test_string);	
	printf(GREY"valid piece: ");
	if (charcount_return == charcount_expected)
		printf(GREEN"%d\n"ENDCOLOR, charcount_return);
	else
		printf(RED"%d\n"ENDCOLOR, charcount_return);
	
	test_string = "....\n....\n####\n...\n\n"; // line too short
	charcount_expected = 0;
	charcount_return = charcount(test_string);	
	printf(GREY"line too short: ");
	if (charcount_return == charcount_expected)
		printf(GREEN"%d\n"ENDCOLOR, charcount_return);
	else
		printf(RED"%d\n"ENDCOLOR, charcount_return);
	
	test_string = "....\n....\n....\n####\n....\n\n"; // block too long
	charcount_expected = 0;
	charcount_return = charcount(test_string);	
	printf(GREY"block too long: ");
	if (charcount_return == charcount_expected)
		printf(GREEN"%d\n"ENDCOLOR, charcount_return);
	else
		printf(RED"%d\n"ENDCOLOR, charcount_return);
	
	test_string =  "....\n....\n....\n#A##\n\n"; // invalid character
	charcount_expected = 0;
	charcount_return = charcount(test_string);	
	printf(GREY"invalid character: ");
	if (charcount_return == charcount_expected)
		printf(GREEN"%d\n"ENDCOLOR, charcount_return);
	else
		printf(RED"%d\n"ENDCOLOR, charcount_return);

/* adjacency_counter() tests */
	printf("\nadjacency_counter() tests\n");
	
	int	adjacent_return;
	int adjacent_expected;

	test_string = ".##.\n.##.\n....\n....\n\n"; // square piece
	adjacent_expected = 8;
	adjacent_return = adjacency_counter(test_string);	
	printf(GREY"square piece: ");
	if (adjacent_return == adjacent_expected)
		printf(GREEN"%d\n"ENDCOLOR, adjacent_return);
	else
		printf(RED"%d\n"ENDCOLOR, adjacent_return);

	test_string = "###.\n.#..\n....\n....\n\n"; // other valid piece
	adjacent_expected = 6;
	adjacent_return = adjacency_counter(test_string);	
	printf(GREY"other valid piece: ");
	if (adjacent_return == adjacent_expected)
		printf(GREEN"%d\n"ENDCOLOR, adjacent_return);
	else
		printf(RED"%d\n"ENDCOLOR, adjacent_return);

	test_string = "#..#\n....\n....\n#..#\n\n"; // zero connections
	adjacent_expected = 0;
	adjacent_return = adjacency_counter(test_string);	
	printf(GREY"zero connections: ");
	if (adjacent_return == adjacent_expected)
		printf(GREEN"%d\n"ENDCOLOR, adjacent_return);
	else
		printf(RED"%d\n"ENDCOLOR, adjacent_return);

	test_string = "##..\n....\n....\n..##\n\n"; // four connections
	adjacent_expected = 4;
	adjacent_return = adjacency_counter(test_string);	
	printf(GREY"four connections: ");
	if (adjacent_return == adjacent_expected)
		printf(GREEN"%d\n"ENDCOLOR, adjacent_return);
	else
		printf(RED"%d\n"ENDCOLOR, adjacent_return);

	test_string = "..#.\n....\n..#.\n.##.\n\n"; // four connections 
	adjacent_expected = 4;
	adjacent_return = adjacency_counter(test_string);	
	printf(GREY"four connections: ");
	if (adjacent_return == adjacent_expected)
		printf(GREEN"%d\n"ENDCOLOR, adjacent_return);
	else
		printf(RED"%d\n"ENDCOLOR, adjacent_return);


/* end tests */

	return (0);
}
