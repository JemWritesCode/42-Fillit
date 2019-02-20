/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:08:47 by jcope             #+#    #+#             */
/*   Updated: 2019/02/20 14:25:56 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "../../libft/libft.h"

typedef struct		s_piece
{
	int				blockcoords[8];
	char			pieceletter;
	struct s_piece	*next; // next has to be a pointer to the next structure in the linked list. 
}					t_piece;

typedef struct	s_map
{
	char		**array;
}				t_map;

size_t	count_pieces(t_piece *piecelist);
void	print_map(t_map *map, int size);
int		round_up_sq_rt(int num);
t_map	*new_map(int size);
t_map	*solve(t_piece *piecelist);
char	*parser(char *filename);

#endif
