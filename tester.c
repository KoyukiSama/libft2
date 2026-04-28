/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:38:41 by kaclaes           #+#    #+#             */
/*   Updated: 2026/04/28 20:23:57 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <bsd/string.h>
#include <unistd.h>

#include <stdio.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"

static int norm(int x)
{
	return (x != 0);
}

void test_str(char *name, char *a, char *b)
{
	static int total = 0;
	static int pass = 0;

	total++;
	if ((a == NULL && b == NULL) || (a && b && strcmp(a, b) == 0))
	{
		printf("\033[32mPASS: %s\n\033[0m", name);
		pass++;
	}
	else
		printf("\033[31mFAIL: %s (got=\"%s\" expected=\"%s\")\n\033[0m",
			name, a ? a : "NULL", b ? b : "NULL");
}

void test_mem(char *name, void *a, void *b, size_t n)
{
	static int total = 0;
	static int pass = 0;

	total++;
	if (!memcmp(a, b, n))
	{
		printf("\033[32mPASS: %s\n\033[0m", name);
		pass++;
	}
	else
		printf("\033[31mFAIL: %s\n\033[0m", name);
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

void test_memset(void)
{
	printf("=== memset ===\n");

	char a[20];
	char b[20];

	memset(a, '0', 20);
	memset(b, '0', 20);
	test_mem("memset full", ft_memset(a, 'a', 20), memset(b, 'a', 20), 20);

	memset(a, '0', 20);
	memset(b, '0', 20);
	ft_memset(a, 'a', 0);
	test_mem("memset len 0", a, b, 20);
}

void test_bzero(void)
{
	printf("=== bzero ===\n");

	char a[20];
	char b[20];

	memset(a, 'a', 20);
	memset(b, 'a', 20);

	ft_bzero(a, 10);
	bzero(b, 10);

	test_mem("bzero partial", a, b, 20);

	ft_bzero(a, 0);
	bzero(b, 0);

	test_mem("bzero zero", a, b, 20);
}

void test_memcpy(void)
{
	printf("=== memcpy ===\n");

	char a[20];
	char b[20];

	memset(a, '0', 20);
	memset(b, '0', 20);

	ft_memcpy(a, "hello", 6);
	memcpy(b, "hello", 6);

	test_mem("memcpy basic", a, b, 20);

	// edge: zero bytes
	ft_memcpy(a, b, 0);
	test_mem("memcpy size 0", a, b, 20);
}

void test_memmove(void)
{
	printf("=== memmove ===\n");

	char a[20] = "1234567890";
	char b[20] = "1234567890";

	ft_memmove(a + 2, a, 5);
	memmove(b + 2, b, 5);

	test_mem("memmove overlap forward", a, b, 20);

	char c[20] = "1234567890";
	char d[20] = "1234567890";

	ft_memmove(c, c + 2, 5);
	memmove(d, d + 2, 5);

	test_mem("memmove overlap backward", c, d, 20);
}

void test_memchr(void)
{
	printf("=== memchr ===\n");

	char s[] = "hello world";

	char *a = ft_memchr(s, 'o', strlen(s));
	char *b = memchr(s, 'o', strlen(s));

	test_mem("memchr find", a, b, sizeof(char*));

	char *c = ft_memchr(s, 'z', strlen(s));
	char *d = memchr(s, 'z', strlen(s));

	test_mem("memchr not found", &c, &d, sizeof(char*));
}

void test_memcmp(void)
{
	printf("=== memcmp ===\n");

	char a[] = "abcde";
	char b[] = "abcdf";

	test_int("memcmp diff", ft_memcmp(a, b, 5), memcmp(a, b, 5));

	test_int("memcmp same", ft_memcmp(a, a, 5), memcmp(a, a, 5));
}

void test_calloc(void)
{
	printf("=== calloc ===\n");

	char *a = ft_calloc(5, sizeof(char));
	char *b = calloc(5, sizeof(char));

	test_mem("calloc zeroed", a, b, 5);

	free(a);
	free(b);
}

void test_strlen_strdup(void)
{
	printf("=== strlen / strdup ===\n");

	test_int("strlen empty", ft_strlen(""), strlen(""));
	test_int("strlen normal", ft_strlen("hello"), strlen("hello"));

	char *a = ft_strdup("hello world");
	char *b = strdup("hello world");

	test_str("strdup basic", a, b);

	free(a);
	free(b);
}

void test_strlcpy_strlcat(void)
{
	printf("=== strlcpy / strlcat ===\n");

	char a[20];
	char b[20];

	test_int(
		"strlcpy return",
		ft_strlcpy(a, "hello", 20),
		strlcpy(b, "hello", 20)
	);

	test_str("strlcpy result", a, b);

	char c[20] = "abc";
	char d[20] = "abc";

	test_int(
		"strlcat return",
		ft_strlcat(c, "def", 20),
		strlcat(d, "def", 20)
	);

	test_str("strlcat result", c, d);
}

void test_strchr_strrchr(void)
{
	printf("=== strchr / strrchr ===\n");

	char *s = "hello world";

	test_str("strchr o",
		ft_strchr(s, 'o'),
		strchr(s, 'o')
	);

	test_str("strrchr o",
		ft_strrchr(s, 'o'),
		strrchr(s, 'o')
	);

	test_str("strchr not found",
		ft_strchr(s, 'z'),
		strchr(s, 'z')
	);
}

void test_strncmp_strnstr(void)
{
	printf("=== strncmp / strnstr ===\n");

	test_int(
		"strncmp",
		ft_strncmp("abc", "abd", 3),
		strncmp("abc", "abd", 3)
	);
}

void test_strnstr(void)
{
	printf("=== strnstr ===\n");

	char *s = "hello world";

	// basic
	test_str("basic",
		ft_strnstr(s, "world", 11),
		"world");

	// not found
	test_str("not found",
		ft_strnstr(s, "zzz", 11),
		NULL);

	// len too small
	test_str("len cutoff",
		ft_strnstr(s, "world", 5),
		NULL);

	// exact boundary
	test_str("boundary",
		ft_strnstr(s, "lo", 5),
		"lo world");

	// empty needle
	test_str("empty needle",
		ft_strnstr(s, "", 5),
		s);

	// empty haystack
	test_str("empty haystack",
		ft_strnstr("", "a", 5),
		NULL);
}

void test_substr(void)
{
	printf("=== substr ===\n");

	test_str("basic",
		ft_substr("hello world", 0, 5),
		"hello");

	test_str("middle",
		ft_substr("hello world", 6, 5),
		"world");

	test_str("len overflow",
		ft_substr("hi", 0, 100),
		"hi");

	test_str("start beyond",
		ft_substr("hi", 10, 5),
		"");

	test_str("empty",
		ft_substr("", 0, 5),
		"");
}

void test_strjoin(void)
{
	printf("=== strjoin ===\n");

	test_str("basic",
		ft_strjoin("hello", "world"),
		"helloworld");

	test_str("empty left",
		ft_strjoin("", "abc"),
		"abc");

	test_str("empty right",
		ft_strjoin("abc", ""),
		"abc");

	test_str("both empty",
		ft_strjoin("", ""),
		"");
}

void test_strtrim(void)
{
	printf("=== strtrim ===\n");

	test_str("basic",
		ft_strtrim("  hello  ", " "),
		"hello");

	test_str("no trim",
		ft_strtrim("hello", " "),
		"hello");

	test_str("full trim",
		ft_strtrim("aaaa", "a"),
		"");

	test_str("mixed set",
		ft_strtrim("xyhelloxy", "xy"),
		"hello");

	test_str("empty string",
		ft_strtrim("", " "),
		"");
}

void test_split(void)
{
	printf("=== split ===\n");

	char **res = ft_split("a b c", ' ');

	test_str("0", res[0], "a");
	test_str("1", res[1], "b");
	test_str("2", res[2], "c");
	test_str("end", res[3], NULL);

	for (int i = 0; res[i]; i++)
		free(res[i]);
	free(res);

	// edge cases
	res = ft_split("   a   b   ", ' ');

	test_str("skip spaces 0", res[0], "a");
	test_str("skip spaces 1", res[1], "b");
	test_str("end2", res[2], NULL);

	for (int i = 0; res[i]; i++)
		free(res[i]);
	free(res);
}

void test_itoa(void)
{
	printf("=== itoa ===\n");

	test_str("0", ft_itoa(0), "0");
	test_str("positive", ft_itoa(123), "123");
	test_str("negative", ft_itoa(-123), "-123");
	test_str("min int", ft_itoa(-2147483648), "-2147483648");
}

char f(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return c - 32;
	return c;
}

void test_strmapi(void)
{
	printf("=== strmapi ===\n");

	test_str("basic",
		ft_strmapi("hello", f),
		"HELLO");

	test_str("empty",
		ft_strmapi("", f),
		"");
}

void g(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
}

void test_striteri(void)
{
	printf("=== striteri ===\n");

	char s[] = "hello";
	ft_striteri(s, g);

	test_str("mutate",
		s,
		"HeLlO");
}

void test_fd(void)
{
	printf("=== fd functions ===\n");

	ft_putchar_fd('A', 1);
	write(1, "\n", 1);

	ft_putstr_fd("hello", 1);
	write(1, "\n", 1);

	ft_putendl_fd("world", 1);

	ft_putnbr_fd(-12345, 1);
	write(1, "\n", 1);
}

void test_atoi(void)
{
	printf("=== atoi ===\n");

	test_int("simple", ft_atoi("42"), 42);
	test_int("negative", ft_atoi("-42"), -42);
	test_int("positive sign", ft_atoi("+42"), 42);

	test_int("leading spaces", ft_atoi("   123"), 123);
	test_int("tabs/newlines", ft_atoi("\t\n 456"), 456);

	test_int("stops on char", ft_atoi("123abc"), 123);
	test_int("starts invalid", ft_atoi("abc123"), 0);

	test_int("zero", ft_atoi("0"), 0);
	test_int("negative zero", ft_atoi("-0"), 0);

	test_int("int max", ft_atoi("2147483647"), 2147483647);
	test_int("int min", ft_atoi("-2147483648"), -2147483648);
}

int	main(void)
{
	// chars
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();

	// mem
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	test_calloc();

	// str funcs
	test_strlen_strdup();
	test_strlcpy_strlcat();
	test_strchr_strrchr();
	test_strncmp_strnstr();

	// more str and convert
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	test_atoi();

	// test fd
	test_fd();
}
