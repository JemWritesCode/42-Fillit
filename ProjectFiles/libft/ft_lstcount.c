/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 20:03:27 by jcope             #+#    #+#             */
/*   Updated: 2019/02/15 20:04:15 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstcount(t_list *list)
{
	size_t	count;

	count = 0;
	while (list != NULL)
	{
		list = list->next;
		count++;
	}
	return (count);
}
