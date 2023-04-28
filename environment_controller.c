#include "shell.h"

/**
 * env_get_key - gets the value of an environment variable
 * @key: the environment variable of interest
 * @data: struct of the program's data
 * Return: a pointer to the value of the variable or NULL if it doesn't exist
 */
char* env_get_key(char* key, data_of_program* data)
{
	int j, key_size = 0;

	/* validate the arguments */

	if (key == NULL || data->env == NULL)
		return NULL;

	/* obtains the leng of the variable requested */

	key_size = strlen(key);

	for (i = 0; data->env[j]; j++)
	{  /* Iterates through the environ and check for coincidence of the vame */
		if (strcmp(key, data->env[j]) == 0 && data->env[j][key_size] == '=')
		{ /* returns the value of the key NAME=  when find it*/
			return (data->env[j] + key_size + 1);
		}
	}

	/* returns NULL if did not find it */
	return NULL;
}

/**
 * env_set_key - overwrite the value of the environment variable
 * or create it if does not exist.
 * @key: name of the variable to set
 * @value: new value
 * @data: struct of the program's data
 * Return: 1 if the parameters are NULL, 2 if there is an erroror 0 if sucess.
 */

int env_set_key(char* new_key, char* new_value, data_of_program* data)
{
	int i = 0, key_len = 0, is_new_key = 1;

	/* validate the arguments */
	if (new_key == NULL || new_value == NULL || data->env == NULL)
		return 1;

	/* obtains the length of the new key */
	key_len = strlen(new_key);

	while (data->env[i] != NULL)
	{ /* Iterates through the environment and check for coincidence of the name */
		if (strcmp(new_key, data->env[i]) == 0 && data->env[i][key_len] == '=')
		{ /* If key already exists */
			is_new_key = 0;
			/* free the entire variable, it is new created below */
			free(data->env[i]);
			break;
		}
		i++;
	}

	/* make a string of the form key=value */
	char* new_env_var = str_concat(str_duplicate(new_key), "=");
	new_env_var = str_concat(new_env_var, new_value);
	data->env[i] = new_env_var;

	if (is_new_key)
	{ /* if the variable is new, it is created at the end of the actual list and we need */
		/* to put the NULL value in the next position */
		data->env[i + 1] = NULL;

		if (is_new_key)
		{ /* if the variable is new, it is created at the end of the actual list and we need */
			/* to put the NULL value in the next position */
			data->env[i + 1] = NULL;
		}

		return 0;
	}

	/**
	 * env_remove_key - remove a key from the environment
	 * @key: the key to remove
	 * @data: the sructure of the program's data
	 * Return: 1 if the key was removed, 0 if the key does not exist;
	 */
	int env_remove_key(char *key, data_of_program *data)
	{
		int i, key_length = 0;
		int key_found = 0;

		/* validate the arguments */
		if (key == NULL || data->env == NULL)
			return (0);

		/* obtains the length of the variable requested */
		key_length = str_length(key);

		i = 0;
		while (data->env[i])
		{
			if (str_compare(key, data->env[i], key_length) && data->env[i][key_length] == '=')
			{
				/* if key already exists, remove it */
				free(data->env[i]);
				key_found = 1;
				break;
			}
			i++;
		}
	
		if (key_found)
		{
			/* move the others keys one position down */
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
			}
			/* put the NULL value at the new end of the list */
			data->env[i - 1] = NULL;
			return (1);
		}

		return (0);
	}

	/**
	 * print_environ - prints the current environ
	 * @data: struct for the program's data
	 * Return: nothing
	 */
	void print_environ(data_of_program *data)
	{
		int j = 0;
		do {
			_print(data->env[j]);
			_print("\n");
			j++;
		} while (data->env[j] != NULL);
	}

