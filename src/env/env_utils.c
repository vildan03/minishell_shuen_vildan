#include "minishell.h"

void free_env_list(t_env *env)
{
    t_env   *current;
    t_env   *next;

    current = env;
    while (current != NULL)
    {
        next = current->next;
        if (current->key != NULL)
            free(current->key);
        if (current->value != NULL)
            free(current->value);
        free(current);
        current = next;
    }
}

void append_env_node(t_env **head, t_env *new_node)
{
    t_env *current;

    if (!head || !new_node)
        return;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
}

void extract_key_value(char *env_str, char **key, char **value)
{
    char    *equals_pos;
    int     key_len;

    equals_pos = ft_strchr(env_str, '=');
    if (equals_pos == NULL)
    {
        *key = ft_strdup(env_str);
        *value = NULL;
        return;
    }
    key_len = equals_pos - env_str;
    *key = ft_substr(env_str, 0, key_len);
    *value = ft_strdup(equals_pos + 1);
}

t_env *init_env(char **envp)
{
    t_env   *head;
    t_env   *new_node;
    int     i;

    head = NULL;
    i = 0;
    if (!envp)
        return (NULL);
    while (envp[i] != NULL)
    {
        new_node = malloc(sizeof(t_env));
        if (!new_node)
            return (head);
        extract_key_value(envp[i], &(new_node->key), &(new_node->value));
        new_node->next = NULL;
        append_env_node(&head, new_node);
        i++;
    }
    return (head);
}
