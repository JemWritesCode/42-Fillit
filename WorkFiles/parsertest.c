/*
**	Test function for the various elements of parser.c
*/

#include "../ProjectFiles/fillitproject/includes/fillit.h"
#include <stdio.h>

t_piece *printpiecelist(t_piece *piecelist);
void	printpiece(t_piece *piece);

t_piece		*makepiece(char* buf, char pieceletter)
{
	t_piece	*piece_ptr;

	piece_ptr = (t_piece*)malloc(sizeof(t_piece));

	int	x;
	int y;
	int i;

	i = 0;
	x = 0;
	y = 1;
	int test = 0;
	while(i < 20)
	{
		if(buf[i] == '#')
		{
			printf("i value at %dth block: %d\n", test, i);
			test++;	
			printf("current i: %d \n", i);
			piece_ptr->blockcoords[x] = (i > 5) ? (i % 5) : i;
			piece_ptr->blockcoords[y] = i / 5;
			printf("x: %d\ny: %d\n", x, y); 

			x += 2;
			y += 2;
		}
		i++;
	}

	//test to print coords
	printf("coords: ");
	i = -1;
	while (i < 7)
		printf("%d, ", piece_ptr->blockcoords[++i]);
	printf("\n");
	//endtest
	
	piece_ptr->pieceletter = pieceletter;
	//align(piece_ptr);
	return (piece_ptr);
}

t_piece		*makelist(char *buf) // too many lines -- may be best to edit validity checker to work on entire file instead of chunks, to be called in parser -- would save 5 lines
{
	t_piece *current;
	t_piece *beginning;
	int 	i;
	char	pieceletter;

	i = 0;
	pieceletter = 'A';
	while (buf[i])
	{
		if (valid(buf + i))
		{
			if (pieceletter == 'A')
			{
				beginning = makepiece(buf + i, pieceletter);
				current = beginning;
			}
			else
			{
				current->next = makepiece(buf + i, pieceletter);
				current = current->next;
			}
			pieceletter++;
		}
		else
			return (NULL);
		i = i+21;
	}
	return (beginning);
}

t_piece		*parser(char *filename)
{
	char	buf[545];
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buf, 545);
	printf("\nbytecount: %d", bytecount);
	if (bytecount > 544 || bytecount < 20)
		return (NULL);
	buf[bytecount] = '\0';
	return (makelist(buf));
}

int	main(void)
{
	t_piece *listhead = makepiece("....\n.##.\n.##.\n....\n\n", 'A');

	//test to print coords
	printf("coords after running makepiece: ");
	int i = -1;
	while (i < 7)
	{
		printf("%d, ", listhead->blockcoords[i]);
		i++;
	}
	printf(" %d\n", listhead->blockcoords[i]);
	//endtest
	
	printpiece(listhead);
	return (0);	
}
