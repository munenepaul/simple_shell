#include "shell.h"

/**
 * list_builtins - search for match and execute the associate builtin
 * @data: struct for the program's data
 * Return: Returns the return of the function executed is there is a match,
 * otherwise returns -1.
 */
int builtins_list(data_of_program *data)
{
	int cursor;
	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};

	iterator = 0;
	while (options[iterator].builtin != NULL) {
		    // code block
		    iterator++;
		    {
			    if (str_compare(options[iterator].builtin, data->command_name, 0))
			    {
				    return (options[iterator].function(data));
			    }
		    }
		    return (-1);
	}
}
