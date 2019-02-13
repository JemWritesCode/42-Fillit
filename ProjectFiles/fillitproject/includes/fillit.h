/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:08:47 by jcope             #+#    #+#             */
/*   Updated: 2019/02/12 17:36:38 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "../../libft/libft.h"

char	*parser(char *filename);

typedef struct	s_piece
{
	int			width;
	int			height;
	char		**piecemap;
	char		pieceletter;
}				t_piece;

#endif
