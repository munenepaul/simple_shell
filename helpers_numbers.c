#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * long_to_string - converts a number to a string.
 * @number: number to be converted in a string.
 * @string: buffer to save the number as string.
 * @base: base to convert number.
 *
 * Return: Nothing.
 */
void long_to_string(long number, char *string, int base)
{
	char *p = string;

	if (number < 0)
	{
		*p++ = '-';
		number = -number;
	}
	if (number == 0)
	{
		*p++ = '0';
	}
	else
	{
		char buf[50];
		int i = 0;

		while (number != 0)
		{
			buf[i++] = "0123456789abcdef"[number % base];
			number /= base;
		}
		while (i-- > 0)
		{
			*p++ = buf[i];
		}
	}
	*p = '\0';
}

/**
 * _atoi - convert a string to an integer.
 *
 * @s: pointer to str origin.
 *
 * Return: integer representation of string or 0.
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;

	while (isspace(*s))
	{
		s++;
	}
	if (*s == '+' || *s == '-')
	{
		sign = (*s == '-') ? -1 : 1;
		s++;
	}
	while (isdigit(*s))
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result * sign);
}

/**
 * count_characters - count the occurrences of character in string.
 *
 * @string: pointer to str origin.
 * @character: string with chars to be counted.
 *
 * Return: number of occurrences of character in string.
 */
int count_characters(char *string, char *character)
{
	int counter = 0;

	while (*string)
	{
		if (*string == *character)
		{
			counter++;
		}
		string++;
	}
	return (counter);
}
