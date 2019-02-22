/*
**	Test function for the various elements of parser.c
*/

#include "../ProjectFiles/fillitproject/includes/fillit.h"
#include <stdio.h>

t_piece *printpiecelist(t_piece *piecelist);

t_piece		*parser(char *filename)
{
	t_piece *TEST = NULL;
	char	buf[545];
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buf, 545);
	printf("\nbytecount: %d", bytecount);
	if (bytecount > 544 || bytecount < 20)
		return (NULL);
	buf[bytecount] = '\0';
	return (TEST);
}

int	main(void)
{
	parser("TestFiles/26Pieces");
	return (0);	
}
