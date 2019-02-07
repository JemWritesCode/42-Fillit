/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:01:38 by jcope             #+#    #+#             */
/*   Updated: 2018/10/22 23:02:56 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	x;
	size_t	k;
	char	**n;

	i = 0;
	k = 0;
	if (!s || !(n = (char **)malloc(sizeof(char*) * (ft_wc((char*)s, c) + 1))))
		return (NULL);
	while (i < ft_wc((char*)s, c))
	{
		if (!(n[i] = (char *)malloc(sizeof(char) * (ft_wlen(&s[k], c) + 1))))
			return (NULL);
		x = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			n[i][x++] = s[k++];
		n[i][x] = '\0';
		i++;
	}
	n[i] = NULL;
	return (n);
}
