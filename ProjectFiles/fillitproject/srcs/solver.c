/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:38:59 by jcope             #+#    #+#             */
/*   Updated: 2019/02/15 19:39:00 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h> // For Testing, remove this!

int		overlap(t_map *map, t_piece *piece, int x_offset, int y_offset)
{
	int	avail;
	int x;
	int y;
	

	x = 0;
	y = 1;
	avail = 0;
	
	printf("LETTER: %c\n", piece->pieceletter );
	//printf("x: %d, y: %d\n", piece->blockcoords[y] + y_offset, piece->blockcoords[x] + x_offset);
	while(x <= 6 && map->array[piece->blockcoords[y] + y_offset][piece->blockcoords[x]+ x_offset] == '.')
	{
		
		//printf("%s\n", "Space Avail");
		avail++;
		x += 2;
		y += 2;

	}       
	//printf("avail: %d\n", avail);
	return (avail != 4);
}

void	place(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int x;
	int y;
	

	x = 0;
	y = 1;
	while(x <= 6)
	{
		
		map->array[piece->blockcoords[y] + y_offset][piece->blockcoords[x] + x_offset] = piece->pieceletter;
		x += 2;
		y += 2;		
	}
	printf("\n");

}

// int		in_bounds(t_piece *piece, int map_size)
// {
// 
// 		return (0);
// }

int		solve_map(t_map *map, t_piece *piece, int map_size)
{	
	if(piece->blockcoords[1] + piece->y_offset <= map_size && 
		piece->blockcoords[3] + piece->y_offset <= map_size && 
		piece->blockcoords[5] + piece->y_offset <= map_size &&
	 	piece->blockcoords[7] + piece->y_offset <= map_size)
	{
		if(piece->blockcoords[0] + piece->x_offset <= map_size &&
			 	piece->blockcoords[2] + piece->x_offset <= map_size && 
				piece->blockcoords[4] + piece->x_offset <= map_size &&
				piece->blockcoords[6] + piece->x_offset <= map_size)
		{
			// For Testing Only
			printf("piece->piece->blockcoords[0] + piece->x_offset: %d\n", (piece->blockcoords[0] + piece->x_offset));
			printf("piece->piece->blockcoords[1] + piece->y_offset: %d\n", (piece->blockcoords[1] + piece->y_offset));
			printf("piece->piece->blockcoords[2] + piece->x_offset: %d\n", (piece->blockcoords[2] + piece->x_offset));
			printf("piece->piece->blockcoords[3] + piece->y_offset: %d\n", (piece->blockcoords[3] + piece->y_offset));
			printf("piece->piece->blockcoords[4] + piece->x_offset: %d\n", (piece->blockcoords[4] + piece->x_offset));
			printf("piece->piece->blockcoords[5] + piece->y_offset: %d\n", (piece->blockcoords[5] + piece->y_offset));	
			printf("piece->piece->blockcoords[6] + piece->x_offset: %d\n", (piece->blockcoords[6] + piece->x_offset));
			printf("piece->piece->blockcoords[7] + piece->y_offset: %d\n", (piece->blockcoords[7] + piece->y_offset));
			
				if (!overlap(map, piece, piece->x_offset, piece->y_offset))
				{
					place(piece, map, piece->x_offset, piece->y_offset);
					if(piece->next)
						return (solve_map(map, piece->next, map_size));
				}
				else
				{
					// Just testing out D since it'll require snap left & map grow. 
					// if(piece->pieceletter == 'D'){
					// 	
					// 	
					// }
					piece->x_offset++;
					solve_map(map, piece, map_size);
				}
		}
		else
		{
			piece->x_offset = 0;
			piece->y_offset++;
			solve_map(map, piece, map_size);
		}	
	}
	return (0);//not solved


		//base case // exit
		// > If there's no more pieces.
		// > If you can't solve the map, exit so we can try again with a bigger map_size. 

			// move the piece and try to solve.
			//this may be backwards. (nope)

			//y cords


			//if it can't place it there in the bounds then it needs to put it back to the far left and then move it down one 
			//then start moving to the right again.

			//need to also account for Sample 3 problem where I need to restart at the first piece and try moving that
			// before I try increasing the map size. 



// 1 = not solved
// 0 = solved.
// cause it gets flipped by the !
}

/*
* Get the square root and round it up for starting map map_size.
* Example: If the number of blocks in pieces would require a 2.3 x 2.3 grid
* then it needs to round up to be 3x3 minimum to fit.
* In that case this function would return 3.
*/

int		round_up_sq_rt(int num)
{
	int	map_size;

	map_size = 2;
	while (map_size * map_size < num)
		map_size++;
	return(map_size);
}

/*
* Start with the smallest map map_size for number of blocks in pieces.
*/

t_map	*solve(t_piece *piecelist)
{
	t_map	*map;
	int		map_size;

	map_size = round_up_sq_rt(count_pieces(piecelist) * 4);
	map = new_map(map_size);
	//while (!solve_map(map, piecelist, map_size))
	//{
	//	map_size++;
	//	//free_map(map);
	//	map = new_map(map_size);
	//}
	printf("!SolveMap Returns: %d\n", !solve_map(map, piecelist, map_size)); // Testing Only
	print_map(map, map_size);
	return(map);
}
