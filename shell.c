#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT_MSG "$ "

/**
 * handle_ctrl_c - handles the SIGINT signal
 * @signal: signal number
 */
void handle_ctrl_c(int signal)
{
    printf("\n%s", PROMPT_MSG);
}

/**
 * main - entry point of the program
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: array of environment variables
 *
 * Return: 0 on success, otherwise an error code
 */
int main(int argc, char *argv[], char *env[])
{
    char *prompt = "";
    signal(SIGINT, handle_ctrl_c);

    if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
    {
        prompt = PROMPT_MSG;
    }

    while (1)
    {
        printf("%s", prompt);
        char input[1024] = "";
        if (fgets(input, 1024, stdin) == NULL)
        {
            perror("fgets");
            exit(1);
        }
        input[strcspn(input, "\n")] = '\0'; // remove newline character
        // do something with input
    }

    return (0);
}
