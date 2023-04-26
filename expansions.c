#include "shell.h"

/**
 * expand_variables - expand variables
 * @data: a pointer to a struct of the program's data
 *
 * Return: nothing, but sets errno.
 */
void expand_variables(data_of_program *data)
{
	int i = 0, j = 0;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;
	buffer_add(line, data->input_line);

	while (line[i])
	{
		if (line[i] == '#')
		{
			line[i--] = '\0';
		}
		else if (line[i] == '$' && line[i + 1] == '?')
		{
			line[i] = '\0';
			long_to_string(errno, expansion, 10);
			buffer_add(line, expansion);
			buffer_add(line, data->input_line + i + 2);
			i += 2;
		}
		else if (line[i] == '$' && line[i + 1] == '$')
		{
			line[i] = '\0';
			long_to_string(getpid(), expansion, 10);
			buffer_add(line, expansion);
			buffer_add(line, data->input_line + i + 2);
			i += 2;
		}
		else if (line[i] == '$' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
		{
			i++;
			continue;
		}
		else if (line[i] == '$')
		{
			for (j = 1; line[i + j] && line[i + j] != ' '; j++)
			{
				expansion[j - 1] = line[i + j];
			}
			temp = env_get_key(expansion, data);
			line[i] = '\0';
			expansion[0] = '\0';
			buffer_add(expansion, line + i + j);
			temp ? buffer_add(line, temp) : 1;
			buffer_add(line, expansion);
			i += j;
		}
		else
		{
			i++;
		}
	}

	if (!str_compare(data->input_line, line, 0))
	{
		free(data->input_line);
		data->input_line = str_duplicate(line);
	}
}


/**
 * expand_alias - expand aliases
 * @data: a pointer to a struct of the program's data
 *
 * Return: nothing, but sets errno.
 */
void expand_alias(data_of_program *data)
{
	char line[BUFFER_SIZE] = {0}, *token, *temp;
	int was_expanded = 0;


	if (data->input_line == NULL)
		return;

	buffer_add(line, data->input_line);

	token = strtok(line, " ");
	while (token != NULL)
	{
		temp = get_alias(data, token);
		if (temp)
		{
			free(token);
			token = str_duplicate(temp);
			was_expanded = 1;
		}

		buffer_add(data->expanded_line, token);
		buffer_add(data->expanded_line, " ");

		token = strtok(NULL, " ");
	}

	if (was_expanded)
	{
		free(data->input_line);
		data->input_line = str_duplicate(data->expanded_line);
	}
}

/**
 * buffer_add - append string at end of the buffer
 * @buffer: buffer to be filled
 * @str_to_add: string to be copied in the buffer
 * Return: nothing, but sets errno.
 */
int buffer_add(char *buffer, char *str_to_add)
{
	int length, i;

	length = str_length(buffer);
	for (i = 0; str_to_add[i]; i++)
	{
		buffer[length + i] = str_to_add[i];
	}
	buffer[length + i] = '\0';
	return (length + i);
}
