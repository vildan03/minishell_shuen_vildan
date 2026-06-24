*This project has been created as part of the 42 curriculum by kerlee and vikaradu*

# Minishell

## Description

Minishell is a small Unix shell written in C as part of the 42 curriculum. The goal of
the project is to understand how a shell works by rebuilding core behaviors such as
command execution, pipes, redirections, environment variable expansion, signal handling,
and built-in commands.

This implementation supports the mandatory shell features from the subject, including:

- an interactive prompt with history
- executable lookup through `PATH`, relative paths, and absolute paths
- single quotes and double quotes
- environment expansion with `$VAR` and `$?`
- redirections `<`, `>`, `<<`, `>>`
- pipelines with `|`
- signal handling for `Ctrl-C`, `Ctrl-D`, and `Ctrl-\`
- built-ins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`

This repository also contains bonus-oriented work, including logical operators with
parentheses and wildcard expansion in the current working directory.

## Instructions

### Requirements

- `cc`
- `make`
- the `readline` library

### Build

```bash
make \\ For mandatory
make bonus \\ For Bonuses
```

### Run

```bash
./minishell
```

### Clean

```bash
make clean
make fclean
make re \\ Only for Mandatory
```

### Valgrind

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=readline.supp ./minishell
```

(Please use the provided readline.supp to hide all readline memory leak errors)
- readline.supp:
```
{
    Ignore_Readline_Leaks
    Memcheck:Leak
    match-leak-kinds: reachable,definite,indirect,possible
    ...
    obj:*/libreadline.so*
}
{
    Ignore_Add_History_Leaks
    Memcheck:Leak
    match-leak-kinds: reachable,definite,indirect,possible
    ...
    fun:add_history
}
{
    Ignore_LibHistory_Leaks
    Memcheck:Leak
    ...
    obj:*/libhistory.so*
}
```

## Project Structure

- `src/main`: input loop, prompt handling, and shell lifecycle
- `src/parser`: lexer, syntax checks, and AST construction
- `src/expander`: variable expansion and wildcard expansion
- `src/executor`: built-ins, external commands, pipes, redirections, and heredocs
- `libft`: custom utility library used by the project

## Additional Information

### Why We Used Structs Instead of Linked Lists in Some Places

We used `struct`s for grouped temporary state when the data belonged together and had
a fixed shape. Examples include quote-tracking during expansion, heredoc state, and
other helper contexts used inside one execution flow.

We preferred `struct`s over linked lists there because:

- the number of fields was fixed and known in advance
- the data was short-lived and passed together between helper functions
- access by field name is clearer than walking a node chain
- it reduced argument count while keeping the logic readable and norm-friendly
- memory management stayed simpler because there was no need for extra node allocation

We still used linked-list-style structures where the data is naturally variable in size,
such as token streams, AST relations, redirections, and heredoc fd tracking. In other
words, we chose the data structure based on the shape of the problem, not by forcing a
single pattern everywhere.

### General Design Choices

Our main choices in the project were guided by a few practical rules:

- follow the subject first and avoid implementing behavior that is outside scope
- use Bash as the reference whenever the subject leaves room for interpretation
- prefer the simplest data structure that matches the job
- keep parsing, expansion, and execution separated so bugs are easier to isolate
- minimize global state and keep the single global variable limited to signal status
- prioritize predictable cleanup paths for memory, fds, and child processes
- adapt helper abstractions to the Norm when functions became too long or took too many
  arguments

For example:

- environment data is kept in `char **` form because it matches `execve` directly
- the parser builds an AST because pipes, parentheses, and logical operators are easier
  to evaluate with a tree structure
- temporary execution state is often stored in `struct`s because it is easier to pass
  and maintain than many separate parameters
- dynamic shell syntax elements such as tokens and redirections are represented with
  linked structures because their size is not fixed

## Resources

### Classic References

- 42 Minishell subject
- GNU Bash Manual
- GNU Readline Library Manual
- man pages for `readline`, `fork`, `execve`, `pipe`, `dup`, `dup2`, `waitpid`,
  `signal`, `sigaction`, `open`, `close`, `opendir`, and `readdir`

### AI Usage

AI tools were used as support during the project for:

- debugging ideas and test case generation
- checking edge cases and comparing behaviors with Bash
- clarifying system-call behavior and signal handling
- improving explanations
