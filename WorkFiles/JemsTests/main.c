//Jem's Tests 

#include "../../ProjectFiles/fillitproject/includes/fillit.h"
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
	printf("\n%s\n%s\n%s\n%s\n\n", piecemap[0], piecemap[1], piecemap[2], piecemap[3]);
}

t_piece *printpiecelist(t_piece *piecelist)
{
	t_piece *listhead = piecelist;
	
	while (piecelist->next)
	{
		printf("piece %c\n", piecelist->pieceletter);
		printcoords(piecelist);
		printpiece(piecelist);
		piecelist = piecelist->next;
	}
	printf("piece %c\n", piecelist->pieceletter);
	printcoords(piecelist);
	printpiece(piecelist);
	return (listhead);
}

int 	main(void ){

// should print 5x5 of dots.
//t_map *map;
//int map_size = 5;
//map = new_map(map_size);

// print_map(map, map_size); 
// 
// printf("\n\n");
// print_map(map, 5); 

// Fake pieces for testing.

//	printf("TEST CASE FOR FITS WITH ONLY HORIZONTAL MOVES."); 
//	t_piece first = {{0, 0, 0, 1, 1, 0, 1, 1}, 'A', 0, 0, NULL};
//	t_piece second = {{0, 0, 0, 1, 0, 2, 0, 3}, 'B', 0, 0, NULL};
//	t_piece third = {{0, 0, 0, 1, 0, 2, 0, 3}, 'C', 0, 0, NULL};
//	t_piece fourth = {{0, 0, 0, 1, 0, 2, 0, 3}, 'D', 0, 0, NULL};
//	//t_piece fourth = {{1, 0, 1, 1, 1, 2, 0, 2}, 'D', 0, 0, NULL};
//	first.next = &second;
//	second.next = &third;
//	third.next = NULL;
//	third.next = &fourth;
//	t_piece *listhead = &first;


	printf("TEST CASE REQUIRES SHIFT BACK TO LEFT AND THEN MOVE RIGHT. NO MAP GROWTH"); 
	t_piece first = {{0, 0, 0, 1, 1, 0, 1, 1}, 'A', 0, 0, NULL};
	t_piece second = {{0, 0, 0, 1, 0, 2, 0, 3}, 'B', 0, 0, NULL};
	t_piece third = {{0, 0, 0, 1, 0, 2, 0, 3}, 'C', 0, 0, NULL};
	t_piece fourth = {{0, 0, 0, 1, 1, 0, 1, 1}, 'D', 0, 0, NULL}; // square
	//t_piece fourth = {{1, 0, 1, 1, 1, 2, 0, 2}, 'D', 0, 0, NULL}; // L
	first.next = &second;
	second.next = &third;
	//third.next = NULL;
	third.next = &fourth;
	t_piece *listhead = &first;

//	printf("TEST CASE REQUIRES SHIFT BACK TO LEFT AND THEN MOVE RIGHT && MAP GROWTH"); 
//	t_piece first = {{0, 0, 0, 1, 1, 0, 1, 1}, 'A', 0, 0, NULL};
//	t_piece second = {{0, 0, 0, 1, 0, 2, 0, 3}, 'B', 0, 0, NULL};
//	t_piece third = {{0, 0, 0, 1, 0, 2, 0, 3}, 'C', 0, 0, NULL}; // l
//	//t_piece fourth = {{0, 0, 0, 1, 1, 0, 1, 1}, 'D', 0, 0, NULL}; // square
//	t_piece fourth = {{1, 0, 1, 1, 1, 2, 0, 2}, 'D', 0, 0, NULL}; // L
//	first.next = &second;
//	second.next = &third;
//	//third.next = NULL;
//	third.next = &fourth;
//	t_piece *listhead = &first;


//solve_map(map, listhead, map_size);
solve(listhead);

//printf("\nCURRENT SOLUTION MAP\n");
//print_map(map, map_size); 

// printpiecelist(listhead);

// printcoords(&first);
//printpiece(&fourth);
// 
// printcoords(&second);
// printpiece(&second);

}