#include <stdlib.h>
#include <string.h>

size_t str_length(const char *string)
{
return (string ? strlen(string) : 0);
}

char *str_duplicate(const char *string)
{
return (string ? strdup(string) : NULL);
}

int str_compare(const char *string1, const char *string2, size_t number)
{
if (string1 == NULL || string2 == NULL)
return (0);

arduino

if (number == 0)
    return (strcmp(string1, string2) == 0);

return (strncmp(string1, string2, number) == 0);

}

char *str_concat(const char *string1, const char *string2)
{
size_t length1 = str_length(string1);
size_t length2 = str_length(string2);
char *result = malloc(length1 + length2 + 1);

scss

if (result == NULL)
{
    errno = ENOMEM;
    perror("Error");
    return (NULL);
}

memcpy(result, string1, length1);
memcpy(result + length1, string2, length2 + 1);

return (result);

}

void str_reverse(char *string)
{
size_t length = str_length(string);

css

for (size_t i = 0; i < length / 2; i++)
{
    char tmp = string[i];
    string[i] = string[length - i - 1];
    string[length - i - 1] = tmp;
}

}
