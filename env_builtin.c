#include "shell.h"

/**
 * env_builtin - shows the environment where the shell runs
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_env(data_of_program *data)
{
	int j;
	char cpname[50] = "";
	char *var_copy = "";

	if (!data->tokens[1])
		print_environ(data);
	else
	{
	for (j = 0; data->tokens[1][j] != '\0'; j++)
	{
		if (data->tokens[1][j] == '=')
		{
	var_copy = strdup(env_get_key(cpname, data));
if (var_copy != NULL)
env_set_key(cpname, &data->tokens[1][j+1], data);

print_environ(data);
if (!env_get_key(cpname, data))
{
	_print(data->tokens[1]);
	_print("\n");
}
else
{
	env_set_key(cpname, var_copy, data);
	free(var_copy);
}
return (0);
}
cpname[j] = data->tokens[1][j];
}
errno = 2;
perror(data->command_name);
errno = 127;
}
return (0);
}

/**
 * builtin_set_env - ..
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_set_env(data_of_program *data)
{
	if (!data->tokens[1] || !data->tokens[2])
		return (0);
	if (data->tokens[3])
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
data->tokens[1] ? env_set_key(data->tokens[1], data->tokens[2], data) : 0;

return (0);
}

/**
 *  builtin_unset_env - ..
 *  @data: struct for the program's data'
 *  Return: ..
 */
int builtin_unset_env(data_of_program *data)
{
	if (strlen(data->tokens[1]) == 0)
		return (0);
	if (strlen(data->tokens[2]) > 0)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	env_remove_key(data->tokens[1], data);

	return (5);
}
