#include "shell.h"

/**

    find_program - find a program in path

    @data: pointer to the program's data

    Return: 0 if success, errcode otherwise
    */
    int find_program(data_of_program *data)
    {
    char *cmd_path = NULL, *path = NULL, *p = NULL, *end = NULL;
    int ret_code = 0;

    if (!data->command_name)
    return (2);

    if (data->command_name[0] == '/' || data->command_name[0] == '.')
    return (check_file(data->command_name));

    path = env_get_key("PATH", data);
    if (path == NULL || *path == '\0')
    return (errno = 127);

    for (p = path; *p; p = (*end == ':') ? end + 1 : end)
    {
    end = p;
    while (*end && *end != ':')
    end++;
    cmd_path = strndup(p, end - p);
    if (cmd_path == NULL)
    return (perror("strndup"), 2);
    char *cmd = str_concat(cmd_path, "/");
    if (cmd == NULL)
    {
    free(cmd_path);
    return (2);
    }
    cmd = str_concat(cmd, data->command_name);
    if (cmd == NULL)
    {
    free(cmd_path);
    return (2);
    }
    ret_code = check_file(cmd);
    if (ret_code == 0 || ret_code == 126)
    {
    errno = 0;
    free(data->tokens[0]);
    data->tokens[0] = cmd;
    free(cmd_path);
    free(path);
    return (ret_code);
    }
    free(cmd);
    free(cmd_path);
    }
    free(path);
    data->tokens[0] = NULL;
    return (ret_code);
    }
