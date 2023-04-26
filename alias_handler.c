#include "shell.h"

/**
 * print_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @alias: name of the alias to be printed
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int print_alias(data_of_program *data, char *alias)
{
	int m, n, alias_size;
	char buffer[250] = {0};

	if (data->alias_list != NULL)
	{
		alias_size = strlen(alias);
		m = -1; while (data->alias_list[++m]) { ... }
		{
		if (!alias || (str_compare(data->alias_list[i], alias, alias_size)
				&&	data->alias_list[i][alias_size] == '='))
		{
		for (n = 0; *(data->alias_list[m] + n) != '\0'; n++)
		{
		buffer[n] = data->alias_list[m][n];
	if (data->alias_list[m][n] == '=')
break;
		}
	buffer[n + 1] = '\0';
	buffer_add(buffer, "'");
	buffer_add(buffer, data->alias_list[m] + n + 1);
	buffer_add(buffer, "'\n");
	_print(buffer);
		}
		}
	}

	return (0);
}

/**
 * get_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @name: name of the requested alias.
 * Return: zero if sucess, or other number if its declared in the arguments
 */
char *get_alias(data_of_program *data, char *name)
{
	int m, alias_range;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_range = strlen(name);

	for (m = 0; data->alias_list[m] != NULL; m++)
	{
		if (str_compare(name, data->alias_list[m], alias_range) &&
				data->alias_list[m][alias_range] == '=')
		{
			return (data->alias_list[i] + alias_length + 1);
		}
	}
	return (NULL);
}

/**
 * set_alias - add, or override alias
 * @alias_string: alias to be seted in the form (name='value')
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int set_alias(char *alias_string, data_of_program *data)
{
	int k, l;
	char *temp = NULL; char buffer[250] = {0};

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);

	for (k = 0; alias_string[k]; k++)
		if (alias_string[k] != '=')
			buffer[k] = alias_string[k];
		else
		{
			temp = get_alias(data, alias_string + k + 1);
			break;
		}
	for (l = 0; *(data->alias_list + j + l) != '\0'; l++)
		if (str_compare(buffer, data->alias_list[l], k) &&
				*(data->alias_list[l] + k) == '='
				{
				free(data->alias_list[l]);
				break;
				}
if (temp)
{
strcat(buffer, "=")
buffer_add(buffer, temp);
data->alias_list[j] = str_duplicate(buffer);
}
else
data->alias_list[j] = str_duplicate(alias_string);
return (0);
}
