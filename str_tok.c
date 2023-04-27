/**
 * _strtok - tokenizes a string
 * @line: string to tokenize
 * @delim: delimiter characters
 *
 * Return: pointer to the next token, NULL if no more tokens
 */
char *_strtok(char *line, const char *delim)
{
	static char *next_token = NULL;
	char *token;

	if (line != NULL)
		next_token = line;

	if (next_token == NULL || *next_token == '\0')
		return NULL;

	token = next_token;

	while (*next_token != '\0')
	{
		const char *d;
		for (d = delim; *d != '\0'; d++)
		{
			if (*next_token == *d)
			{
				*next_token = '\0';
				next_token++;
				return token;
			}
		}
		next_token++;
	}

	return token;
}
