#include "shell.h"

/**
 * builtin_exit - exit of the program with the status
 * @data: struct for the program's data
 *  Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_exit(data_of_program *data)
{
	int i;

	if (data->tokens[1] != NULL)
	{
		for (i = 0; data->tokens[1][i]; i++)
		{
			if ((data->tokens[1][i] < '0' || data->tokens[1][i] > '9') &&
				data->tokens[1][i] != '+')
			{
			errno = 2;
		return 2;
			}
		}
	/* Convert argument to integer and set errno */
	errno = atoi(data->tokens[1]);
	}
/* Free all data and exit with errno */
free_all_data(data);
exit(errno);
}

/**
 * builtin_cd - change the current directory
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_cd(data_of_program *data)
{
	char *dir_home = getenv("HOME");
	char *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (data->tokens[1])
	{
		if (strcmp(data->tokens[1], "-") == 0)
		{
			dir_old = getenv("OLDPWD");
			if (dir_old)
				error_code = chdir(dir_old);
			printf("%s\n", getenv("PWD"));

			return error_code;
		}
		else
		{
			return chdir(data->tokens[1]);
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return chdir(dir_home);
	}

	return (0);
}

/**
 * set_work_directory - set the work directory
 *  @data: struct for the program's data
 *  @new_dir: path to be set as work directory
 *  Return: zero if sucess, or other number if its declared in the arguments
 */
struct data_of_program {
	/* Define data structure of program here */
};

int str_compare(char *str1, char *str2, int case_sensitive) {
	/* Define the string compare function here */
}

void env_set_key(char *key, char *value, struct data_of_program *data) {
	/* Define the environment variable set function here */
}
int set_work_directory(struct data_of_program *data, char *new_dir) {
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);
	if (!str_compare(old_dir, new_dir, 0)) {
		err_code = chdir(new_dir);
		if (err_code == -1) {
			errno = 2;
			return 3;
		}
		env_set_key("PWD", new_dir, data);
	}
	env_set_key("OLDPWD", old_dir, data);
	return 0;
}

/**
 * builtin_help - shows the environment where the shell runs
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_help(data_of_program *data)
{
	int m, width = 0;
	char *mensajes[6] = {NULL};

	mensajes[0] = HELP_MSG;

	/* validate args */
	if (data->tokens[1] == NULL)
	{
		_print(mensajes[0] + 6);
		return (1);
	}
	if (*(data->tokens + 2) != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	mensajes[1] = HELP_EXIT_MSG;
	mensajes[2] = HELP_ENV_MSG;
	mensajes[3] = HELP_SETENV_MSG;
	mensajes[4] = HELP_UNSETENV_MSG;
	mensajes[5] = HELP_CD_MSG;

	for (m = 0; mensajes[m]; m++)
	{
		/*print the length of string */
		width = str_length(data->tokens[1]);
		if (str_compare(data->tokens[1], mensajes[i], width))
		{
			_print(mensajes[m] + length + 1);
			return (1);
		}
	}
	/*if there is no match, print error and return -1 */
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}

/**
 * builtin_alias - add, remove or show aliases
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_alias(data_of_program *data)
{
	int j = 0;

	if (data->tokens[1] == NULL)
		return (print_alias(data, NULL));

	while (data->tokens[++i])
	{/* if there are arguments, set or print each env variable*/
		if (count_characters(data->tokens[i], "="))
			set_alias(data->tokens[i], data);
		else
			print_alias(data, data->tokens[i]);
	}

	return (0);
}

