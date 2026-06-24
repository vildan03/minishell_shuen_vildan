# Evaluation Checklist

## Automated Checks

```bash
make
make bonus
make
./subject_eval_test.sh
```

Expected:

- `make` and `make bonus` compile cleanly
- the second `make` does not relink
- `subject_eval_test.sh` only prints failing cases

## Manual Interactive Checks

Run:

```bash
./minishell
```

Then check:

- empty prompt + `Ctrl-C`: new line and fresh prompt
- empty prompt + `Ctrl-\`: nothing happens
- empty prompt + `Ctrl-D`: shell exits
- type `abc`, then `Ctrl-C`, then `Enter`: buffer must be clean, `abc` must not run
- type `abc`, then `Ctrl-D`: shell must not exit
- type `abc`, then `Ctrl-\`: nothing happens
- run `cat`, then `Ctrl-C`: command stops and prompt returns
- run `cat`, then `Ctrl-\`: behavior should match bash
- run `cat`, then `Ctrl-D`: behavior should match bash
- run a few commands, then test `Up` and `Down` history navigation

## Manual Valgrind Checks

Run:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=readline.supp ./minishell
```

Inside minishell, test:

- `cat`, then `Ctrl-C`
- `<< eof`, then `Ctrl-C`
- `echo hi | cat`
- `exit`

Expected:

- no leaks from project code
- no real fd leaks from project code
- `<inherited from parent>` lines are external and not a minishell leak
