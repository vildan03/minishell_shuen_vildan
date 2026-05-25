#include "minishell.h"

char *extract_and_replace_var(char *str, int *i, t_env *env, int last_status)
{
    int     start;
    char    *key;
    char    *val_dup;

    (*i)++;
    if (str[*i] == '?')
    {
        (*i)++;
        return (ft_itoa(last_status)); 
    }
    start = *i;
    while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
        (*i)++;
    key = ft_substr(str, start, *i - start);
    val_dup = ft_strdup(get_env_value(key, env));
    free(key);
    return (val_dup);
}

char *process_var(char *res, char *raw, int *i, t_env *env, int status)
{
    char *tmp;

    tmp = extract_and_replace_var(raw, i, env, status);
    res = append_string(res, tmp);
    free(tmp);
    return (res);
}

char *expand_string(char *raw, t_env *env, int status)
{
    int     sq;
    int     dq;
    int     i;
    char    *res;

    sq = 0;
    dq = 0;
    i = 0;
    res = ft_strdup("");
    while (raw[i])
    {
        if (raw[i] == '\'' && !dq)
        {
            sq = !sq;
            i++;
        }
        else if (raw[i] == '\"' && !sq)
        {
            dq = !dq;
            i++;
        }
        else if (raw[i] == '$' && !sq && is_env_char(raw[i + 1]))
            res = process_var(res, raw, &i, env, status);
        else
            res = append_char(res, raw[i++]);
    }
    return (res);
}

void expand_redirections(t_redir *redir_list, t_env *env, int status)
{
    t_redir *current;
    char    *expanded_file;

    current = redir_list;
    while (current != NULL)
    {
	printf("  -> [DEBUG] Redir BEFORE: '%s'\n", current->file);

        expanded_file = expand_string(current->file, env, status);
        free(current->file);
        current->file = expanded_file;
	printf("  -> [DEBUG] Redir AFTER:  '%s'\n", current->file);
        
        current = current->next;
    }
}

void expand_command_args(t_ast_node *node, t_env *env, int last_status)
{
    int     i;
    char    *expanded_str;

    if (!node || !node->args)
        return;
        
    i = 0;
    while (node->args[i] != NULL)
    {
        expanded_str = expand_string(node->args[i], env, last_status);
        free(node->args[i]);
        node->args[i] = expanded_str;
        i++;
    }
    expand_redirections(node->redir, env, last_status);
}
