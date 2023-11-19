#include "monty.h"

/**
 * _strlen - checks length
 * @str: string to check
 * Return: len
 */

int _strlen(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

/**
 * *_strtokenizer - tokenizes string
 * @str: string to tokenize
 * @delimiters: delimiters
 * Return: token
 */

char *_strtokenizer(char *str, const char *delimiters)
{
	static char *final_string;
	char *first_token;

	if (str != NULL)
	{
		final_string = str;
	}

	if (final_string == NULL || *final_string == '\0')
	{
		return (NULL);
	}

	while (*final_string != '\0' && strchr(delimiters, *final_string) != NULL)
	{
		final_string++;
	}

	if (*final_string == '\0')
	{
		return (NULL);
	}

	first_token = final_string;

	while (*final_string != '\0' && strchr(delimiters, *final_string) == NULL)
	{
		final_string++;
	}

	if (*final_string != '\0')
	{
		*final_string = '\0';
		final_string++;
	}

	return (first_token);
}


/**
 * _strcmp - compares two strings
 * @string1: string 1
 * @string2: string 2
 * Return: true for 0,false for  1
 */

int _strcmp(char *string1, char *string2)
{
	int i = 0;

	while (string1[i] != '\0' && string2[i] != '\0')
	{
		if (string1[i] != string2[i])
		{
			return (string1[i] - string2[i]);
		}
		i++;
	}

	return (0);
}

/**
 * frees - free a stack
 * @head: stack
 * Return: void
 */

void frees(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * _isdi - checks if string is digit
 * @str: string to check
 * Return: if true 1 if false 0
 */

int _isdi(char *str)
{
	if (!str || *str == '\0')
	{
		return (0);
	}
	if (*str == '-')
	{
		str++;
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}

		str++;
	}

	return (1);
}
