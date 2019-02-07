/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_non_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:01:38 by jcope             #+#    #+#             */
/*   Updated: 2018/10/22 23:02:56 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_non_spaces(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (!ft_isspace(*str))
			count++;
		str++;
	}
	return (count);
}
