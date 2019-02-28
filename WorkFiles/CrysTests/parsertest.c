/*
**	Test function for the various elements of parser.c
*/

#include <stdio.h>
#include "fillit.h"

t_piece *printpiecelist(t_piece *piecelist);
void	printpiece(t_piece *piece);

#define GREEN "\e[38;5;83m"
#define RED "\e[38;5;160m"
#define GREY "\e[38;5;241m"
#define ENDCOLOR "\e[0m"
#include <stdio.h>

int	main(void)
{
	char *filepath;

	filepath = "../TestFiles/valid_allhorizontals";
	printf(GREY"%s\n"ENDCOLOR, filepath);
	printpiecelist(parser(filepath));

	filepath = "../TestFiles/valid_allverticals";
	printf(GREY"%s\n"ENDCOLOR, filepath);
	printpiecelist(parser(filepath));

	filepath = "../TestFiles/valid_allsquares";
	printf(GREY"%s\n"ENDCOLOR, filepath);
	printpiecelist(parser(filepath));

	return (0);	
}
