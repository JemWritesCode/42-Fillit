/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validitychecker_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:31:20 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/24 23:24:37 by cschulle         ###   ########.fr       */
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
	ret[bytecount] = '\0';
	return (ret);
}

int main(void)
{

/* valid() tests */
	printf("valid() tests\n");

	char	buf[545];

	char *filepath1 = "../TestFiles/valid_1";
	char *testbuf1 = readfile(filepath1);
	int	size1 = ft_strlen(testbuf1);
	char *filepath2 = "../TestFiles/valid_2";
	char *testbuf2 = readfile(filepath2);
	int	size2 = ft_strlen(testbuf2);
	char *filepath3 = "../TestFiles/valid_3";
	char *testbuf3 = readfile(filepath3);
	int	size3 = ft_strlen(testbuf3);
	char *filepath4 = "../TestFiles/valid_4";
	char *testbuf4 = readfile(filepath4);
	int	size4 = ft_strlen(testbuf4);
	char *filepath5 = "../TestFiles/valid_5";
	char *testbuf5 = readfile(filepath5);
	int	size5 = ft_strlen(testbuf5);
	char *filepath6 = "../TestFiles/valid_6";
	char *testbuf6 = readfile(filepath6);
	int	size6 = ft_strlen(testbuf6);
	char *filepath7 = "../TestFiles/valid_7";
	char *testbuf7 = readfile(filepath7);
	int	size7 = ft_strlen(testbuf7);
	char *filepath8 = "../TestFiles/26Pieces";
	char *testbuf8 = readfile(filepath8);
	int	size8 = ft_strlen(testbuf8);

//	printf(GREY"file contents for %s: \n%s"ENDCOLOR, filepath1, testbuf1);
	printf(GREY"valid() return for %s: "ENDCOLOR"%d\n", filepath1, valid(testbuf1, size1));
	printf(GREY"valid() return for %s: "ENDCOLOR"%d\n", filepath2, valid(testbuf2, size2));
	printf(GREY"valid() return for %s: "ENDCOLOR"%d\n", filepath3, valid(testbuf3, size3));
	printf(GREY"valid() return for %s: "ENDCOLOR"%d\n", filepath4, valid(testbuf4, size4));
	printf(GREY"valid() return for %s: "ENDCOLOR"%d\n", filepath5, valid(testbuf5, size5));
	printf(GREY"valid() return for %s: "ENDCOLOR"%d\n", filepath6, valid(testbuf6, size6));
	printf(GREY"valid() return for %s: "ENDCOLOR"%d\n", filepath7, valid(testbuf7, size7));
	printf(GREY"valid() return for %s: "ENDCOLOR"%d\n", filepath8, valid(testbuf8, size8));
		
//	printf(GREY"charcount() return for %s: "ENDCOLOR"%d\n", filepath1, charcount(testbuf1));
//	printf(GREY"adjacency_counter() return for %s: "ENDCOLOR"%d\n", filepath1, adjacency_counter(testbuf1));


/* charcount() tests */
/*	printf("\ncharcount() tests\n");

	char *test1 = "....\n.##.\n.##.\n....\n"; // valid piece
	char *test2 = "...\n....\n....\n####\n\n"; // line too short
	char *test3 = "....\n....\n....\n####\n....\n\n"; // block too long
	char *test4 = "....\n....\n....\n#A##\n\n"; // invalid character

	int ret1 = charcount(test1);
	int ret2 = charcount(test2);
	int ret3 = charcount(test3);
	int ret4 = charcount(test4);
	
	printf(GREY"test 1: ");
	if (ret1 == 4)
		printf(GREEN"pass "GREY"(returns 4 if piece is valid)\n"ENDCOLOR);
	else
		printf(RED"fail "GREY"(rejects a valid piece with return %d)\n", ret1);
	
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
