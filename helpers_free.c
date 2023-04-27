#include "shell.h"

/**
 * free_recurrent_data - free the fields needed each loop
 * @data: struct of the program's data
 * Return: void
 */
void free_recurrent_data(data_of_program *data)
{
	if (data->tokens != NULL)
		free_array_of_pointers(data->tokens);

	if (data->input_line != NULL)
		free(data->input_line);

	if (data->command_name != NULL)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * free_all_data - free all field of the data
 * @data: struct of the program's data
 * Return: void
 */
void free_all_data(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor) == -1)
			perror(data->program_name);
	}

	free_recurrent_data(data);

	if (data->env != NULL)
		free_array_of_pointers(data->env);

	if (data->alias_list != NULL)
		free_array_of_pointers(data->alias_list);
}

/**
 * free_array_of_pointers - frees each pointer of an array of pointers and the
 * array itself
 * @array: array of pointers
 * Return: void
 */
void free_array_of_pointers(char **array)
{
	int i = 0;

	if (array == NULL)
		return;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}

	free(array);
}
