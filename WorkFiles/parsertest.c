/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsertest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:22:02 by cschulle          #+#    #+#             */
/*   Updated: 2019/02/07 21:25:20 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	WHAT THIS DOES
**	This is a test to verify that parser() is correctly reading valid input files,
**	and null-terminating at the right length. 
**	Double check that relative paths are correct if this file has been moved.
*/

#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

int main(void)
{
	printf("16 = %d\n",	ft_strlen(parser("../../WorkFiles/TestFiles/valid_1")));
	printf("32 = %d\n",	ft_strlen(parser("../../WorkFiles/TestFiles/valid_2")));
	printf("48 = %d\n", ft_strlen(parser("../../WorkFiles/TestFiles/valid_3")));
	printf("64 = %d\n", ft_strlen(parser("../../WorkFiles/TestFiles/valid_4")));
	printf("80 = %d\n", ft_strlen(parser("../../WorkFiles/TestFiles/valid_5")));
	printf("96 = %d\n", ft_strlen(parser("../../WorkFiles/TestFiles/valid_6")));
	printf("112 = %d\n", ft_strlen(parser("../../WorkFiles/TestFiles/valid_7")));
	printf("128 = %d\n", ft_strlen(parser("../../WorkFiles/TestFiles/valid_8")));

	printf("1 = %s\n", (parser("../../WorkFiles/TestFiles/valid_1")));
	printf("2 = %s\n", (parser("../../WorkFiles/TestFiles/valid_2")));
	printf("3 = %s\n", (parser("../../WorkFiles/TestFiles/valid_3")));
	printf("4 = %s\n", (parser("../../WorkFiles/TestFiles/valid_4")));
	printf("5 = %s\n", (parser("../../WorkFiles/TestFiles/valid_5")));
	printf("6 = %s\n", (parser("../../WorkFiles/TestFiles/valid_6")));
	printf("7 = %s\n", (parser("../../WorkFiles/TestFiles/valid_7")));
	printf("8 = %s\n", (parser("../../WorkFiles/TestFiles/valid_8")));
	return(0);
}
