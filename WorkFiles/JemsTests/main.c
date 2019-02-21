//Jem's Tests 

#include "../../ProjectFiles/fillitproject/includes/fillit.h"
#include <stdio.h>

int 	main(void ){

// should print 5x5 of dots.
t_map *map;
map = new_map(5);
print_map(map, 5); 

place(map, 2, 1, 'A'); // just testing putting things on the map. this prob will be inside of solve_map
printf("\n\n");
print_map(map, 5); 


	t_piece *listhead;
	t_piece *first;
	t_piece *second;
	t_piece *third;

	listhead = &first;
	first->blockcoords = {0, 0, 0, 1, 0, 2, 0, 3};
	first->pieceletter = A;
	first->next = second;

	second->blockcoords = {0, 0, 1, 0, 0, 1, 1, 1};
	second->pieceletter = B;
	second->next = third;

	third->blockcoords = {1, 0, 1, 1, 1, 2, 0, 2};
	third->pieceletter = C;
	third->next = NULL;

solve_map(map, listhead, map_size);

}