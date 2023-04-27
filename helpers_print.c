#include "shell.h"

/**
 * _print - writes a string to stdout
 * @string: pointer to the string
 *
 * Return: the number of bytes written or -1 on failure
 */
int _print(char *string)
{
	if (!string)
		return (-1);

	size_t len = strlen(string);

	ssize_t bytes_written = write(STDOUT_FILENO, string, len);

	if (bytes_written < 0)
		perror("_print");

	return (bytes_written);
}

/**
 * _printe - writes a string to stderr
 * @string: pointer to the string
 *
 * Return: the number of bytes written or -1 on failure
 */
int _printe(char *string)
{
	if (!string)
		return (-1);

	size_t len = strlen(string);


	ssize_t bytes_written = write(STDERR_FILENO, string, len);

	if (bytes_written < 0)
		perror("_printe");

	return (bytes_written);
}

/**
 * _print_error - writes an error message to stderr
 * @errorcode: the error code
 * @data: pointer to the program's data
 *
 * Return: the number of bytes written or -1 on failure
 */
int _print_error(int errorcode, data_of_program *data)
{
	if (!data || !data->program_name || !data->tokens[0] ||
	    (!data->tokens[1] && (errorcode == 2 || errorcode == 3)))
		return (-1);


	char n_as_string[10] = {'\0'};

	long_to_string((long)data->exec_counter, n_as_string, 10);

	int ret = 0;

	switch (errorcode)
	{
	case 2:
	case 3:
		ret = _printe(data->program_name) +
			_printe(": ") +
			_printe(n_as_string) +
			_printe(": ") +
			_printe(data->tokens[0]) +
			_printe(": Illegal number: ") +
			_printe(data->tokens[1]) +
			_printe("\n");
		break;
	case 127:
		ret = _printe(data->program_name) +
			_printe(": ") +
			_printe(n_as_string) +
			_printe(": ") +
			_printe(data->command_name) +
			_printe(": not found\n");
		break;
	case 126:
		ret = _printe(data->program_name) +
			_printe(": ") +
			_printe(n_as_string) +
			_printe(": ") +
			_printe(data->command_name) +
			_printe(": Permission denied\n");
		break;
	default:
		break;
	}

	return (ret);
}
