#include <stdbool.h>

int execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pidd;

	/* check for program in built ins */
	retval = builtins_list(data);
	if (retval != -1) /* if program was found in built ins */
		return (retval);

	}
/* Check for program in file system */
retval = find_program(data);
if (!retval) {
	/* If program was found */
	found_program = true;
}

if (!found_program) {
	/* If program not found */
	return retval;
}

/* If program was found */
pid = fork();
if (pid == -1) {
	/* If the fork call failed */
	perror(data->command_name);
	exit(EXIT_FAILURE);
}

if (pid == 0) {

	/* I am the child process, I execute the program */
	retval = execve(data->tokens[0], data->tokens, data->env);
	if (retval == -1) {
		/* If error when execve */
		perror(data->command_name);
		exit(EXIT_FAILURE);
	}
} else {
	/* I am the father, I wait and check the exit status of the child */
	while (wait(&status) != pid);
	if (WIFEXITED(status)) {
		errno = WEXITSTATUS(status);
		} else if (WIFSIGNALED(status)) {
			errno = 128 + WTERMSIG(status);
		}
}
return 0;
		
