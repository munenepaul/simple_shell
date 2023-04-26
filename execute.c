

int execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pidd;

	/* check for program in built ins */
	retval = builtins_list(data);
	if (retval != -1) /* if program was found in built ins */
		return (retval);

	/* check for program file system */
	retval = find_program(data);
	if (retval)
		{ /* if program not found */
			return (retval);
		}
	else
		
