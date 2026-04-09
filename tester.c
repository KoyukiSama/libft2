/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:38:41 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/09 15:55:22 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <string.h>

#include <stdio.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"

int	main(void)
{
	char	char1 = 0;
	int		int1 = 0;
	int		error = 0;

	printf("----TEST_FUNC00: ft_alpha()----\n");
	printf(RED);
	char1 = '@';
	if (ft_isalpha(char1) != 0)
		printf("ERROR ft_isalpha(%c)\n", char1), error = 1;
	char1 = 'A';
	if (ft_isalpha(char1) == 0)
		printf("ERROR ft_isalpha(%c)\n", char1), error = 1;
	char1 = 'Z';
	if (ft_isalpha(char1) == 0)
		printf("ERROR ft_isalpha(%c)\n", char1), error = 1;
	char1 = '[';
	if (ft_isalpha(char1) != 0)
		printf("ERROR ft_isalpha(%c)\n", char1), error = 1;
	char1 = '`';
	if (ft_isalpha(char1) != 0)
		printf("ERROR ft_isalpha(%c)\n", char1), error = 1;
	char1 = 'a';
	if (ft_isalpha(char1) == 0)
		printf("ERROR ft_isalpha(%c)\n", char1), error = 1;
	char1 = 'z';
	if (ft_isalpha(char1) == 0)
		printf("ERROR ft_isalpha(%c)\n", char1), error = 1;
	char1 = '{';
	if (ft_isalpha(char1) != 0)
		printf("ERROR ft_isalpha(%c)\n", char1), error = 1;
	printf(GRN);
	if (!error)
		printf("PASS: ft_isdigit\n");
	printf(RESET);

	printf("----TEST_FUNC01: ft_isdigit()----\n");
	printf(RED);
	char1 = '/';
	if (ft_isdigit(char1) != 0)
		printf("ERROR ft_isdigit(%c)\n", char1), error = 1;
	char1 = '0';
	if (ft_isdigit(char1) == 0)
		printf("ERROR ft_isdigit(%c)\n", char1), error = 1;
	char1 = '9';
	if (ft_isdigit(char1) == 0)
		printf("ERROR ft_isdigit(%c)\n", char1), error = 1;
	char1 = ':';
	if (ft_isdigit(char1) != 0)
		printf("ERROR ft_isdigit(%c)\n", char1), error = 1;
	printf(GRN);
	if (!error)
		printf("PASS: ft_isdigit()\n");
	printf(RESET);

	printf("----TEST_FUNC02: ft_isalnum()----\n");
	printf(RED);
	char1 = '@';
	if (ft_isalnum(char1) != 0)
		printf("ERROR ft_isalnum(%c)\n", char1), error = 1;
	char1 = 'A';
	if (ft_isalnum(char1) == 0)
		printf("ERROR ft_isalnum(%c)\n", char1), error = 1;
	char1 = 'Z';
	if (ft_isalnum(char1) == 0)
		printf("ERROR ft_isalnum(%c)\n", char1), error = 1;
	char1 = '[';
	if (ft_isalnum(char1) != 0)
		printf("ERROR ft_isalnum(%c)\n", char1), error = 1;
	char1 = '`';
	if (ft_isalnum(char1) != 0)
		printf("ERROR ft_isalnum(%c)\n", char1), error = 1;
	char1 = 'a';
	if (ft_isalnum(char1) == 0)
		printf("ERROR ft_isalnum(%c)\n", char1), error = 1;
	char1 = 'z';
	if (ft_isalnum(char1) == 0)
		printf("ERROR ft_isalnum(%c)\n", char1), error = 1;
	char1 = '{';
	if (ft_isalnum(char1) != 0)
		printf("ERROR ft_isalnum(%c)\n", char1), error = 1;
	char1 = '/';
	if (ft_isalnum(char1) != 0)
		printf("ERROR ft_isalnum(%c)\n", char1), error = 1;
	char1 = '0';
	if (ft_isalnum(char1) == 0)
		printf("ERROR ft_isalnum(%c)\n", char1), error = 1;
	char1 = '9';
	if (ft_isalnum(char1) == 0)
		printf("ERROR ft_isalnum(%c)\n", char1), error = 1;
	char1 = ':';
	if (ft_isalnum(char1) != 0)
		printf("ERROR ft_isalnum(%c)\n", char1), error = 1;
	printf(GRN);
	if (!error)
		printf("PASS: ft_isalnum()\n");
	printf(RESET);

	printf("----TEST_FUNC03: ft_isascii()----\n");
	printf(RED);
	int1 = -1;
	if (ft_isascii(int1) != 0)
		printf("ERROR ft_isascii(%i)\n", int1), error = 1;
	int1 = 0;
	if (ft_isascii(int1) == 0)
		printf("ERROR ft_isascii(%i)\n", int1), error = 1;
	int1 = 127;
	if (ft_isascii(int1) == 0)
		printf("ERROR ft_isascii(%i)\n", int1), error = 1;
	int1 = 128;
	if (ft_isascii(int1) != 0)
		printf("ERROR ft_isascii(%i)\n", int1), error = 1;
	printf(GRN);
	if (!error)
		printf("PASS: ft_isascii()\n");
	printf(RESET);

	printf("----TEST_FUNC04: ft_isprint()----\n");
	printf(RED);
	int1 = 31;
	if (ft_isprint(int1) != 0)
		printf("ERROR ft_isprint(%i)\n", int1), error = 1;
	int1 = 32;
	if (ft_isprint(int1) == 0)
		printf("ERROR ft_isprint(%i)\n", int1), error = 1;
	int1 = 126;
	if (ft_isprint(int1) == 0)
		printf("ERROR ft_isprint(%i)\n", int1), error = 1;
	int1 = 127;
	if (ft_isprint(int1) != 0)
		printf("ERROR ft_isprint(%i)\n", int1), error = 1;
	printf(GRN);
	if (!error)
		printf("PASS: ft_isprint()\n");
	printf(RESET);

	printf("----TEST_FUNC05: ft_strlen()----\n");
	printf(RED);
	
	if (ft_strlen("hello") != strlen("hello"))
		printf("ERROR ft_strlen(\"hello\")\n"), error = 1;
	if (ft_strlen("") != strlen(""))
		printf("ERROR ft_strlen(\"\"))\n"), error = 1;
	printf(GRN);
	if (!error)
		printf("PASS: ft_strlen()\n");
	printf(RESET);
}
