//Jem's Tests 

#include "../../ProjectFiles/fillitproject/includes/fillit.h"

void	print_map(t_map *map, int size)
{	
	int i;

	i = 0;
	while(i < size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

int 	main(void ){

t_map *map;

map = new_map(5);
print_map(map, 5); // should print 5x5 of dots.

}