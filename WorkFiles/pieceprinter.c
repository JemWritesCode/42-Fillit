/*
** Testing function for printing the parsed pieces in a piecelist
*/

#include "../ProjectFiles/fillitproject/includes/fillit.h"
#include "../ProjectFiles/libft/libft.h"
#include <stdio.h>

void	printcoords(t_piece *piece)
{
	int x = 0;
	int y = 1;

	printf("coords: ");
	while (x < 8)
	{
		printf("(%d, %d) ", piece->blockcoords[x], piece->blockcoords[y]);
		x+=2;
		y+=2;
	}
	printf("\n");
}

void	printpiece(t_piece *piece)
{
	char	piecemap[4][5] = {"....\0", "....\0", "....\0", "....\0"};

	int		i = 0;
	while (i < 8)
	{
		piecemap[piece->blockcoords[i + 1]][piece->blockcoords[i]] = piece->pieceletter;
		i += 2;
	}
	printf(" %s\n %s\n %s\n %s\n\n", piecemap[0], piecemap[1], piecemap[2], piecemap[3]);
}

t_piece *printpiecelist(t_piece *piecelist)
{
	t_piece *listhead = piecelist;
	
	while (piecelist->next)
	{
		printf("Piece %c\n", piecelist->pieceletter);
		printcoords(piecelist);
		printpiece(piecelist);
		piecelist = piecelist->next;
	}
	printf("Piece %c\n", piecelist->pieceletter);
	printcoords(piecelist);
	printpiece(piecelist);
	return (listhead);
}

int		main(void)
{
	t_piece first = {{0, 0, 0, 1, 1, 0, 1, 1}, 'A', NULL};
	t_piece second = {{0, 0, 0, 1, 0, 2, 0, 3}, 'B', NULL};
	t_piece third = {{1, 0, 1, 1, 1, 2, 0, 2}, 'C', NULL};
	first.next = &second;
	second.next = &third;
	t_piece *listhead = &first;

	printpiecelist(listhead);
	return (0);
}
