/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:01:37 by jcope             #+#    #+#             */
/*   Updated: 2018/10/22 23:02:56 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (!*needle)
		return ((char*)hay);
	while (hay[i] && i < len)
	{
		if (ft_strncmp((char *)&hay[i], needle, ft_strlen(needle)) == 0)
		{
			if (i + ft_strlen(needle) > len)
				return (NULL);
			return ((char*)&hay[i]);
		}
		i++;
	}
	return (NULL);
}
