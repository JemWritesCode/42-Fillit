/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:08:47 by jcope             #+#    #+#             */
/*   Updated: 2019/02/27 22:27:46 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <unistd.h>
#include <fcntl.h>
#include "../../libft/libft.h"

typedef struct		s_piece
{
	int				blockcoords[8];
	char			pieceletter;
	int				x_offset;
	int				y_offset;
	struct s_piece	*next; // next has to be a pointer to the next structure in the linked list. 
}				t_piece;

typedef struct	s_map
{
	char		**array;
}				t_map;

int				in_bounds(t_piece *piece, int map_size, char axis);
int				overlap(t_map *map, t_piece *piece, int x_offset, int y_offset);
int				solve_map(t_map *map, t_piece *piecelist, int map_size);
void			place(t_piece *piece, t_map *map, char letter);
size_t			count_pieces(t_piece *piecelist);
void			print_map(t_map *map, int size);
int				round_up_sq_rt(int num);
t_map			*new_map(int size);
t_map			*solve(t_piece *piecelist);
t_piece			*parser(char *filename);
void			shift_x(t_piece *piece, int n);
void			shift_y(t_piece *piece, int y);
int				valid(char *buf, int size);

#endif
