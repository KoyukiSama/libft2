/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:38:41 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/15 16:31:10 by kaclaes          ###   ########.fr       */
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

	printf("----TEST_FUNC06: ft_memset()----\n");
	printf(RED);
	char *block = malloc(20);
	for (int i = 0; i < 20; i++)
		block[i] = '0';
	if (strncmp(ft_memset(block, 'a', 0), "00000000000000000000", 20))
		printf("ERROR ft_memset(block, 'a', 0)\n"), error = 1;
	for (int i = 0; i < 20; i++)
		block[i] = '0';
	if (strncmp(ft_memset(block, 'a', 5), "aaaaa000000000000000", 20))
		printf("ERROR ft_memset(block, 'a', 5)\n"), error = 1;
	printf(GRN);
	if (!error)
		printf("PASS: ft_memset()\n");
	printf(RESET);

	printf("----TEST_FUNC07: ft_bzero()----\n");
	printf(RED);
	for (int i = 0; i < 20; i++)
		block[i] = 'a';
	ft_bzero(block, 0);
	if (strncmp(block, "aaaaaaaaaaaaaaaaaaaa", 20))
		printf("ERROR ft_bzero(block, 'a', 0)\n"), error = 1;
	for (int i = 0; i < 20; i++)
		block[i] = 'a';
	ft_bzero(block, 5);
	if (strncmp(block, "\0\0\0\0\0aaaaaaaaaaaaaaa", 20))
		printf("ERROR ft_bzero(block, 'a', 5)\n"), error = 1;
	printf(GRN);
	if (!error)
		printf("PASS: ft_bzero()\n");
	printf(RESET);

	printf("----TEST_FUNC08: ft_memcpy()----\n");
	printf(RED);
	char *block2 = malloc(20);
	for (int i = 0; i < 20; i++)
	{
		block[i] = 0;
		block2[i] = 'a';
	}
	ft_memcpy(block, block2, 5);
	if (strncmp(block, "aaaaa\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 20))
		printf("ERROR ft_memcpy(block, block2, 5)\n"), error = 1;
	ft_memcpy(block, block2, 20);
	if (strncmp(block, "aaaaaaaaaaaaaaaaaaaa", 20))
		printf("ERROR ft_memcpy(block, block2, 20)\n"), error = 1;
	printf(GRN);
	if (!error)
		printf("PASS: ft_memcpy()\n");
	printf(RESET);

	printf("----TEST_FUNC09: ft_memmove()----\n");
	printf(RED);
	free(block2);
	for (int i = 0; i < 10; i++)
	{
		block[i] = 0;
		block[i + 10] = 'a';
	}
	ft_memmove(block, block + 10, 10);
	if (strncmp(block, "aaaaaaaaaaaaaaaaaaaa", 20))
		printf("ERROR ft_memmove(block, block + 10, 10)\n"), error = 1;
	for (int i = 0; i < 10; i++)
	{
		block[i] = 0;
		block[i + 10] = 'a';
	}
	ft_memmove(block + 10, block, 10);
	if (strncmp(block, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 20))
		printf("ERROR ft_memmove(block + 10, block, 10)\n"), error = 1;
	printf(GRN);
	if (!error)
		printf("PASS: ft_memmove()\n");
	printf(RESET);

	printf("----no tests TEST_FUNC10: ft_strlcpy()----\n");
	printf("----no tests TEST_FUNC10: ft_strlcat()----\n");
	
}
