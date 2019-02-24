/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validitychecker_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:31:20 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/23 23:23:16 by cschulle         ###   ########.fr       */
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
int		valid(char* buf);

char	*readfile(char *filename) // reads the file in for testing -- same functionality as parser()
{
	char	buf[545]; // declared as static here because otherwise is freed once out of scope
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buf, 545);
	char* ret = malloc(bytecount + 1);
	if (bytecount <= 0)
	{	
		printf("invalid file path :(\n");
		return (NULL);
	}
	if (bytecount > 544 || bytecount < 20)
	{
		printf("invalid filesize :(\n");
		return (NULL);
	}
	int i = 0;
	while (i < bytecount)
	{
		ret[i] = buf[i];
		i++;
	}
	buf[bytecount] = '\0';
	return (ret);
}

int main(void)
{

/* valid() tests */
	printf("valid() tests\n");

	char *filepath1 = "../TestFiles/valid_1";
	char *testbuf1 = readfile(filepath1);

	printf(GREY"file contents for %s: \n%s", filepath1, testbuf1);
	printf(GREY"valid() return for %s: "ENDCOLOR"%d\n", filepath1, valid(testbuf1));
	
	printf(GREY"charcount() return for %s: "ENDCOLOR"%d\n", filepath1, charcount(testbuf1));
/* charcount() tests */
/*	printf("\ncharcount() tests\n");

	char *test2 = "...\n....\n....\n####\n\n"; // line too short
	char *test3 = "....\n....\n....\n####\n....\n\n"; // block too long
	char *test4 = "....\n....\n....\n#A##\n\n"; // invalid character
	
	int ret2 = charcount(test2);
	int ret3 = charcount(test3);
	int ret4 = charcount(test4);
	
	printf(GREY"test 2: ");
	if (ret2 == 0)
		printf(GREEN"pass "GREY"(returns error if a line is too short)\n"ENDCOLOR);
	else
		printf(RED"fail "GREY"(doesn't return error if a line is too short)\n");
	
	printf(GREY"test 3: ");
	if (ret3 == 0)
		printf(GREEN"pass "GREY"(returns error if a block is too long\n"ENDCOLOR);
	else
		printf(RED"fail "GREY"(doesn't return error if a block is too long)\n");
	
	printf(GREY"test 4: ");
	if (ret4 == 0)
		printf(GREEN"pass "GREY"(returns error if invalid character\n"ENDCOLOR);
	else
		printf(RED"fail"GREY"(doesn't return error if invalid character)\n");
*/
/* adjacency_counter() tests */
/*	printf("\nadjacency_counter() tests\n");

	char *test5 = "#..#\n....\n....\n#..#\n\n"; // zero connections
	char *test6 = "##..\n....\n....\n..##\n\n"; // four connections
	char *test7 = "..#.\n....\n..#.\n.##.\n\n"; // five connections
	
	int	ret5 = adjacency_counter(test5);
	int	ret6 = adjacency_counter(test6);
	int	ret7 = adjacency_counter(test7);

	printf(GREY"test 5: ");
	if (ret5 == 0)
		printf(GREEN"pass "GREY"(returns error if %d connections)\n"ENDCOLOR, ret5);
	else
		printf(RED"fail "GREY"(doesn't return error if %d connections)\n", ret5);
	
	printf(GREY"test 6: ");
	if (ret6 == 4)
		printf(GREEN"pass "GREY"(returns error if %d connections)\n"ENDCOLOR, ret6);
	else
		printf(RED"fail "GREY"(doesn't return error if %d connections)\n", ret6);

	printf(GREY"test 7: ");
	if (ret7 == 4)
		printf(GREEN"pass "GREY"(returns error if %d connections)\n"ENDCOLOR, ret7);
	else
		printf(RED"fail "GREY"(doesn't return error if %d connections)\n", ret7);
*/
/* end tests */

	return (0);
}
