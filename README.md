*This project has been created as part of the 42 curriculum by <kerlee> and <vikaradu>*

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
make
```

### Run

```bash
./minishell
```

### Clean

```bash
make clean
make fclean
make re
```

### Valgrind

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=readline.supp ./minishell
```

## Project Structure

- `src/main`: input loop, prompt handling, and shell lifecycle
- `src/parser`: lexer, syntax checks, and AST construction
- `src/expander`: variable expansion and wildcard expansion
- `src/executor`: built-ins, external commands, pipes, redirections, and heredocs
- `libft`: custom utility library used by the project

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

All AI-generated suggestions were reviewed manually, discussed between teammates,
adapted to the codebase, and tested before being kept in the project.
