#include "expander.h"
#include "minishell.h"

int is_env_char(char c)
{
    if (ft_isalnum(c) == 1)
        return (1);
    else if (c == '_')
        return (1);
    else if (c == '?')
        return (1);
    else
        return (0);
}

char *append_char(char *str, char c)
{
    char    *new_str;
    int     len;
    int     i;

    len = 0;
    if (str)
        len = ft_strlen(str);
    new_str = malloc(len + 2);
    if (!new_str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = c;
    new_str[i + 1] = '\0';
    free(str);
    return (new_str);
}

char *append_string(char *str, char *append)
{
    char *new_str;

    if (!str || !append)
        return (str);
    new_str = ft_strjoin(str, append);
    free(str);
    return (new_str);
}

char *get_env_value(char *key, t_env *env)
{
    t_env *current = env;

    while (current != NULL)
    {
        if (ft_strcmp(current->key, key) == 0)
            return (current->value);
        current = current->next;
    }
    return (""); 
}
