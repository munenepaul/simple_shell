/**
 * tokenize - Tokenizes the input line into an array of strings
 * @data: Pointer to the program's data
 * Return: An array of the different parts of the string
 */
void tokenize(data_of_program *data)
{
	char *delimiter = " \t";
	char *token;
	int i, counter = 0;

	/* Count the number of tokens */
	for (i = 0; data->input_line[i]; i++)
	{
		if (strchr(delimiter, data->input_line[i]) != NULL &&
		    (i == 0 || strchr(delimiter, data->input_line[i - 1]) == NULL))
		{
			counter++;
		}
	}

	/* Allocate memory for the tokens array */
	data->tokens = malloc((counter + 2) * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}

	/* Extract each token */
	i = 0;
	token = _strtok(data->input_line, delimiter);
	while (token != NULL)
	{
		data->tokens[i++] = token;
		token = _strtok(NULL, delimiter);
	}

	/* Set the command name and add NULL terminator to the tokens array */
	data->command_name = data->tokens[0];
	data->tokens[i] = NULL;
}
