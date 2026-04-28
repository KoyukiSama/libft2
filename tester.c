/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:38:41 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/28 19:40:56 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <string.h>

#include <stdio.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"

static int norm(int x)
{
	return (x != 0);
}

void	test_int(char *name, int a, int b)
{
	static int total = 0;
	static int pass = 0;

	total++;
	if (a == b)
	{

		printf("\033[32mPASS: %s\n\033[0m", name);
		pass++;
	}
	else
		printf("\033[31mFAIL: %s (got=%d expected=%d)\n\033[0m", name, a, b);

	// optional summary (only prints once at end if you want later)
}

void test_isalpha(void)
{
	printf("=== isalpha ===\n");

	int tests[] = {
		'A', 'Z', 'a', 'z',
		'@', '[', '`', '{',
		'0', '9', 127, -1
	};

	for (int i = 0; i < (int)(sizeof(tests)/sizeof(int)); i++)
	{
		char c = (char)tests[i];

		char name[50];
		sprintf(name, "isalpha('%c')", (c >= 32 && c <= 126) ? c : '?');

		test_int(name, ft_isalpha(c), norm(isalpha(c)));
	}
}

void test_isdigit(void)
{
	printf("=== isdigit ===\n");

	for (int c = -5; c <= 130; c++)
	{
		char name[50];
		sprintf(name, "isdigit(%d)", c);

		test_int(name, ft_isdigit(c), norm(isdigit(c)));
	}
}

void test_isalnum(void)
{
	printf("=== isalnum ===\n");

	int checks[] = {
		'A', 'Z', 'a', 'z',
		'0', '9',
		'@', '[', '`', '{',
		' ', 127, -1
	};

	for (int i = 0; i < (int)(sizeof(checks)/sizeof(int)); i++)
	{
		char c = (char)checks[i];

		char name[50];
		sprintf(name, "isalnum('%c')", (c >= 32 && c <= 126) ? c : '?');

		test_int(name, ft_isalnum(c), norm(isalnum(c)));
	}
}

void test_isascii(void)
{
	printf("=== isascii ===\n");

	for (int c = -20; c <= 200; c += 7)
	{
		char name[50];
		sprintf(name, "isascii(%d)", c);

		test_int(name, ft_isascii(c), norm(isascii(c)));
	}
}

void test_isprint(void)
{
	printf("=== isprint ===\n");

	for (int c = -10; c <= 140; c += 5)
	{
		char name[50];
		sprintf(name, "isprint(%d)", c);

		test_int(name, ft_isprint(c), norm(isprint(c)));
	}
}

void test_toupper(void)
{
	printf("=== toupper ===\n");

	for (int c = 0; c <= 140; c += 3)
	{
		char name[50];
		sprintf(name, "toupper(%d)", c);

		test_int(name, ft_toupper(c), toupper(c));
	}
}

void test_tolower(void)
{
	printf("=== tolower ===\n");

	for (int c = 0; c <= 140; c += 3)
	{
		char name[50];
		sprintf(name, "tolower(%d)", c);

		test_int(name, ft_tolower(c), tolower(c));
	}
}

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
}
