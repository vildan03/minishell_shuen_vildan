# Minishell Test Report

## 📊 Execution Summary
- **Total Tests Run**: 744
- **Passed**: 431
- **Required Feature Failures**: 0
- **Out of Scope Differences**: 313
- **Crashes**: 0
- **Timeouts (Hangs)**: 0
- **Signal Handling Failures**: 0
- **Memory/FD Leaks Found**: No

## ❌ Required Feature Failures
> [!IMPORTANT]
> The failures below correspond to standard requirements and bonuses of the project. **These must be fixed.**

*None! All mandatory and bonus requirements passed successfully!* 🎉

## ℹ️ Out of Scope Differences (Non-Required Features)
> [!NOTE]
> The mismatches below involve features explicitly excluded by the subject (e.g. backslashes, semicolons, tildes, or local assignments). **You are NOT required to fix these.**

### Mismatch for Command: `<<<<<`
**Reason**: Skipped: Here strings '<<<' are not required by the subject (Note: Here strings '<<<' are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `<<<<<<<<<<<<<<<<`
**Reason**: Skipped: Here strings '<<<' are not required by the subject (Note: Here strings '<<<' are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `\\`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `\\\\`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `\\\\\\\\`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `&&&&&`
**Reason**: Skipped: Background operator '&' is not required by the subject (Note: Background operator '&' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `;;`
**Reason**: Skipped: Semicolon ';' is not required by the subject (Note: Semicolon ';' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `;;;;;`
**Reason**: Skipped: Semicolon ';' is not required by the subject (Note: Semicolon ';' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `;;;;;;;;;;;;;;;`
**Reason**: Skipped: Semicolon ';' is not required by the subject (Note: Semicolon ';' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `*/*`
**Reason**: Skipped: Wildcard matching outside current directory is not required (Note: Wildcard matching outside current directory is not required)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `*/*`
**Reason**: Skipped: Wildcard matching outside current directory is not required (Note: Wildcard matching outside current directory is not required)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `~`
**Reason**: Skipped: Tilde '~' expansion is not required (Note: Tilde '~' expansion is not required)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `ABC=hola`
**Reason**: Skipped: Local variable assignment without export is not required (Note: Local variable assignment without export is not required)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo      \n hola`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo \$HOME`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo my shit terminal is [$TERM]`
**Reason**: Skipped: Character class wildcards '[]' are not required by the subject (Note: Character class wildcards '[]' are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo my shit terminal is [$TERM4`
**Reason**: Skipped: Character class wildcards '[]' are not required by the subject (Note: Character class wildcards '[]' are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo my shit terminal is [$TERM4]`
**Reason**: Skipped: Character class wildcards '[]' are not required by the subject (Note: Character class wildcards '[]' are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo $UID`
**Reason**: Skipped: Internal shell variable '$UID' is not exported to minishell (Note: Internal shell variable '$UID' is not exported to minishell)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo $UID$HOME`
**Reason**: Skipped: Internal shell variable '$UID' is not exported to minishell (Note: Internal shell variable '$UID' is not exported to minishell)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo $USER$var\$USER$USER\$USERtest$USER`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo $hola*`
**Reason**: stdout mismatch:
  BASH:
bible_test.txt break_minishell.py failed_test.md inc libft Makefile minishell minishell correction.html readline.supp README.md src tester.py tests.txt
  MINISHELL:
Makefile README.md bible_test.txt break_minishell.py failed_test.md inc libft minishell minishell correction.html readline.supp src tester.py tests.txt (Note: Wildcard sorting order difference (ASCII vs dictionary) is out of scope)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**:
  ```
  bible_test.txt break_minishell.py failed_test.md inc libft Makefile minishell minishell correction.html readline.supp README.md src tester.py tests.txt
  ```
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**:
  ```
  Makefile README.md bible_test.txt break_minishell.py failed_test.md inc libft minishell minishell correction.html readline.supp src tester.py tests.txt
  ```
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo *`
**Reason**: stdout mismatch:
  BASH:
bible_test.txt break_minishell.py failed_test.md inc libft Makefile minishell minishell correction.html readline.supp README.md src tester.py tests.txt
  MINISHELL:
Makefile README.md bible_test.txt break_minishell.py failed_test.md inc libft minishell minishell correction.html readline.supp src tester.py tests.txt (Note: Wildcard sorting order difference (ASCII vs dictionary) is out of scope)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**:
  ```
  bible_test.txt break_minishell.py failed_test.md inc libft Makefile minishell minishell correction.html readline.supp README.md src tester.py tests.txt
  ```
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**:
  ```
  Makefile README.md bible_test.txt break_minishell.py failed_test.md inc libft minishell minishell correction.html readline.supp src tester.py tests.txt
  ```
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo $*`
**Reason**: Skipped: Special parameter '$*' is not required by the subject (Note: Special parameter '$*' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola*hola *`
**Reason**: stdout mismatch:
  BASH:
hola*hola bible_test.txt break_minishell.py failed_test.md inc libft Makefile minishell minishell correction.html readline.supp README.md src tester.py tests.txt
  MINISHELL:
hola*hola Makefile README.md bible_test.txt break_minishell.py failed_test.md inc libft minishell minishell correction.html readline.supp src tester.py tests.txt (Note: Wildcard sorting order difference (ASCII vs dictionary) is out of scope)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**:
  ```
  hola*hola bible_test.txt break_minishell.py failed_test.md inc libft Makefile minishell minishell correction.html readline.supp README.md src tester.py tests.txt
  ```
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**:
  ```
  hola*hola Makefile README.md bible_test.txt break_minishell.py failed_test.md inc libft minishell minishell correction.html readline.supp src tester.py tests.txt
  ```
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo $hola*`
**Reason**: stdout mismatch:
  BASH:
bible_test.txt break_minishell.py failed_test.md inc libft Makefile minishell minishell correction.html readline.supp README.md src tester.py tests.txt
  MINISHELL:
Makefile README.md bible_test.txt break_minishell.py failed_test.md inc libft minishell minishell correction.html readline.supp src tester.py tests.txt (Note: Wildcard sorting order difference (ASCII vs dictionary) is out of scope)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**:
  ```
  bible_test.txt break_minishell.py failed_test.md inc libft Makefile minishell minishell correction.html readline.supp README.md src tester.py tests.txt
  ```
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**:
  ```
  Makefile README.md bible_test.txt break_minishell.py failed_test.md inc libft minishell minishell correction.html readline.supp src tester.py tests.txt
  ```
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo $HOME*`
**Reason**: Skipped: Wildcard matching outside current directory is not required (Note: Wildcard matching outside current directory is not required)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `Ctlr-\`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `hola Ctlr-\`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `env hola`
**Reason**: Skipped: env does not require arguments or options (Note: env does not require arguments or options)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `env hola que tal`
**Reason**: Skipped: env does not require arguments or options (Note: env does not require arguments or options)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `env env`
**Reason**: Skipped: env does not require arguments or options (Note: env does not require arguments or options)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `env env env env env`
**Reason**: Skipped: env does not require arguments or options (Note: env does not require arguments or options)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `env ls`
**Reason**: Skipped: env does not require arguments or options (Note: env does not require arguments or options)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `env ./Makefile`
**Reason**: Skipped: env does not require arguments or options (Note: env does not require arguments or options)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export       HOLA=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export Hola\nexport`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export Hola9hey\nexport`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA9=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export _HOLA=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export ___HOLA=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export _HO_LA_=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOL\~A=bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export -HOLA=bonjour`
**Reason**: Skipped: export/unset options/flags are not required by the subject (Note: export/unset options/flags are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export --HOLA=bonjour`
**Reason**: Skipped: export/unset options/flags are not required by the subject (Note: export/unset options/flags are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOL\$A=bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HO\\LA=bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HO$?LA=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA+=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonjour\nexport HOLA+=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `exportHOLA=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA =bonjour`
**Reason**: Skipped: export with spaces around '=' is not standard assignment syntax (Note: export with spaces around '=' is not standard assignment syntax)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA = bonjour`
**Reason**: Skipped: export with spaces around '=' is not standard assignment syntax (Note: export with spaces around '=' is not standard assignment syntax)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bon jour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA= bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonsoir\nexport HOLA=bonretour\nexport HOLA=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=$HOME\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonjour$HOME\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=$HOMEbonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bon$jour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bon\jour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bon\\jour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bon&jour`
**Reason**: Skipped: Background operator '&' is not required by the subject (Note: Background operator '&' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bon@jour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bon;jour\nenv`
**Reason**: Skipped: Semicolon ';' is not required by the subject (Note: Semicolon ';' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bon"jour"\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA$USER=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonjour=casse-toi\necho $HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export "HOLA=bonjour"=casse-toi\necho $HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonjour\nexport BYE=casse-toi\necho $HOLA et $BYE`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonjour BYE=casse-toi\necho $HOLA et $BYE`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export $HOLA=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="bonjour      "\necho $HOLA | cat -e`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="   -n bonjour   "\necho $HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="bonjour   "/\necho $HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA='"'\necho " $HOLA " | cat -e`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=at\nc$HOLA Makefile`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export "" HOLA=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="cat Makefile | grep NAME"\necho $HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=hey\necho $HOLA$HOLA$HOLA=hey$HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="  bonjour  hey  "\necho $HOLA | cat -e`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="  bonjour  hey  "\necho """$HOLA""" | cat -e`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="  bonjour  hey  "\necho wesh"$HOLA" | cat -e`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="  bonjour  hey  "\necho wesh""$HOLA.`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="  bonjour  hey  "\necho wesh$""HOLA.`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="  bonjour  hey  "\necho wesh$"HOLA HOLA".`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonjour\nexport HOLA=" hola et $HOLA"\necho $HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonjour\nexport HOLA=' hola et $HOLA'\necho $HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonjour\nexport HOLA=" hola et $HOLA"$HOLA\necho $HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="ls        -l    - a"\necho $HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="s -la"\nl$HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="s -la"\nl"$HOLA"`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="s -la"\nl'$HOLA'`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="l"\n$HOLAs`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="l"\n"$HOLA"s`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOL=A=bonjour\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="l"\n'$HOLA's`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOL=A=""\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export TE+S=T\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=p\nexport BYE=w\n$HOLA"BYE"d`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=p\nexport BYE=w\n"$HOLA"'$BYE'd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=p\nexport BYE=w\n"$HOLA""$BYE"d`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=p\nexport BYE=w\n$"HOLA"$"BYE"d`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=p\nexport BYE=w\n$'HOLA'$'BYE'd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=-n\n"echo $HOLA" hey`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export A=1 B=2 C=3 D=4 E=5 F=6 G=7 H=8\necho "$A'$B"'$C"$D'$E'"$F'"'$G'$H"`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonjour\nenv\nunset HOLA\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonjour\nenv\nunset HOLA\nunset HOLA\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset PATH\necho $PATH`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset PATH\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset PWD\nenv | grep PWD\npwd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `pwd\nunset PWD\nenv | grep PWD\ncd $PWD\npwd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset OLDPWD\nenv | grep OLDPWD`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset HOL\\\\A`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset HOL;A`
**Reason**: Skipped: Semicolon ';' is not required by the subject (Note: Semicolon ';' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset -HOLA`
**Reason**: Skipped: export/unset options/flags are not required by the subject (Note: export/unset options/flags are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset HOL\~A`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset "" HOLA\nenv | grep HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset PATH\necho $PATH`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset PATH\ncat Makefile`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `history`
**Reason**: Skipped: history builtin is not required by the subject (Note: history builtin is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `pwd -p`
**Reason**: Skipped: pwd does not require options (Note: pwd does not require options)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `pwd --p`
**Reason**: Skipped: pwd does not require options (Note: pwd does not require options)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `pwd ---p`
**Reason**: Skipped: pwd does not require options (Note: pwd does not require options)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `pwd -- p`
**Reason**: Skipped: pwd does not require options (Note: pwd does not require options)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd srcs objs`
**Reason**: Skipped: cd with multiple arguments is not required by the subject (Note: cd with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd //\npwd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd '//'\npwd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd ///\npwd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd ////////\npwd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd '////////'\npwd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd /\ncd ..`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd -`
**Reason**: Skipped: cd options/flags are not required by the subject (Note: cd options/flags are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd --`
**Reason**: Skipped: cd options/flags are not required by the subject (Note: cd options/flags are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd ---`
**Reason**: Skipped: cd options/flags are not required by the subject (Note: cd options/flags are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd $HOME $HOME`
**Reason**: Skipped: cd with multiple arguments is not required by the subject (Note: cd with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset HOME\ncd $HOME`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset HOME\nexport HOME=\ncd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset HOME\nexport HOME\ncd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd minishell Docs crashtest.c`
**Reason**: Skipped: cd with multiple arguments is not required by the subject (Note: cd with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd / | echo $?\npwd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd ~`
**Reason**: Skipped: Tilde '~' expansion is not required (Note: Tilde '~' expansion is not required)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd ~/`
**Reason**: Skipped: Tilde '~' expansion is not required (Note: Tilde '~' expansion is not required)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd ~/ | echo $?\npwd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd *`
**Reason**: Skipped: cd with wildcard is not required by the subject (Note: cd with wildcard is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd *`
**Reason**: Skipped: cd with wildcard is not required by the subject (Note: cd with wildcard is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd *`
**Reason**: Skipped: cd with wildcard is not required by the subject (Note: cd with wildcard is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `mkdir a\nmkdir a/b\ncd a/b\nrm -r ../../a\ncd ..`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `mkdir a\nmkdir a/b\ncd a/b\nrm -r ../../a\npwd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `mkdir a\nmkdir a/b\ncd a/b\nrm -r ../../a\necho $PWD\necho $OLDPWD`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `mkdir a\nmkdir a/b\ncd a/b\nrm -r ../../a\ncd\necho $PWD\necho $OLDPWD`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `mkdir a\ncd a\nrm -r ../a\necho $PWD\necho $OLDPWD`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export CDPATH=/\ncd $HOME/..`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export CDPATH=/\ncd home/vietdu91`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export CDPATH=./\ncd .`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export CDPATH=./\ncd ..`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `chmod 000 minishell\n./minishell`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `env | grep SHLVL\n./minishell\nenv | grep SHLVL\nexit\nenv | grep SHLVL`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `touch hola\n./hola`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `env -i ./minishell\nenv`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `env -i ./minishell\nexport`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `env -i ./minishell\ncd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `env -i ./minishell\ncd ~`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `exit hola que tal`
**Reason**: Skipped: exit with multiple arguments is not required by the subject (Note: exit with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `exit 666 666`
**Reason**: Skipped: exit with multiple arguments is not required by the subject (Note: exit with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `exit -666 666`
**Reason**: Skipped: exit with multiple arguments is not required by the subject (Note: exit with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `exit hola 666`
**Reason**: Skipped: exit with multiple arguments is not required by the subject (Note: exit with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `exit 666 666 666 666`
**Reason**: Skipped: exit with multiple arguments is not required by the subject (Note: exit with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `exit 666 hola 666`
**Reason**: Skipped: exit with multiple arguments is not required by the subject (Note: exit with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `exit hola 666 666`
**Reason**: Skipped: exit with multiple arguments is not required by the subject (Note: exit with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `exit -69 -96`
**Reason**: Skipped: exit with multiple arguments is not required by the subject (Note: exit with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `exit | ls`
**Reason**: Skipped: exit with multiple arguments is not required by the subject (Note: exit with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\nexit | cat -e bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\ncat -e bonjour | exit`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd .. | echo "hola"`
**Reason**: Skipped: cd with multiple arguments is not required by the subject (Note: cd with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd / | echo "hola"`
**Reason**: Skipped: cd with multiple arguments is not required by the subject (Note: cd with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd .. | pwd`
**Reason**: Skipped: cd with multiple arguments is not required by the subject (Note: cd with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `whoami | grep $USER > /tmp/bonjour\ncat /tmp/bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `whoami | cat -e | cat -e > /tmp/bonjour\ncat /tmp/bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `whereis ls | cat -e | cat -e > /tmp/bonjour\ncat /tmp/bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=bonjour | cat -e | cat -e`
**Reason**: Skipped: export/unset options/flags are not required by the subject (Note: export/unset options/flags are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `unset HOLA | cat -e`
**Reason**: Skipped: export/unset options/flags are not required by the subject (Note: export/unset options/flags are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA | echo hola\nenv | grep PROUT`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `exit | sleep 3`
**Reason**: Skipped: exit with multiple arguments is not required by the subject (Note: exit with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > a\n>>b echo que tal\ncat a | <b cat | cat > c | cat`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `ls || ;`
**Reason**: Skipped: Semicolon ';' is not required by the subject (Note: Semicolon ';' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `; || ls`
**Reason**: Skipped: Semicolon ';' is not required by the subject (Note: Semicolon ';' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `ls && ;`
**Reason**: Skipped: Semicolon ';' is not required by the subject (Note: Semicolon ';' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `; && ls`
**Reason**: Skipped: Semicolon ';' is not required by the subject (Note: Semicolon ';' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `(ls && pwd) > hola\ncat hola`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `(> pwd)\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `(< pwd)\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `(ls && pwd | wc) > hola\ncat hola`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `(ls && pwd | wc) > hola\n(ls && pwd | wc) > hola\ncat hola`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `(ls && pwd | wc) >> hola\necho hey&&(ls && pwd | wc) > hola\ncat hola`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hey > hola\n(pwd | wc) < hola`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hey > hola\n(ls && pwd | wc) < hola`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hey > hola\n(ls -z || pwd | wc) < hola`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `(ls > Docs/hey && pwd) > hola\ncat hola\ncat Docs/hey`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `ls > Docs/hey && pwd > hola\ncat hola\ncat Docs/hey`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cd ../.. && pwd && pwd`
**Reason**: Skipped: cd with multiple arguments is not required by the subject (Note: cd with multiple arguments is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `ls -z || cd ../../..&&pwd\npwd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `ls -z || (cd ../../..&&pwd)\npwd`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\ncat bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo que tal >> bonjour\ncat bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho que tal >> bonjour\ncat < bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\nrm bonjour\necho que tal >> bonjour\ncat < bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola que tal > bonjour\ncat bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola que tal > /tmp/bonjour\ncat -e /tmp/bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA=hey\necho bonjour > $HOLA\necho $HOLA`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `whereis grep > Docs/bonjour\ncat Docs/bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `ls -la > Docs/bonjour\ncat Docs/bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `pwd>bonjour\ncat bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `pwd >                     bonjour\ncat bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `> bonjour echo hola\ncat bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `> bonjour | echo hola\ncat bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `prout hola > bonjour\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > hello >> hello >> hello\nls\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > hello >> hello >> hello\necho hola >> hello\ncat < hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > hello >> hello >> hello\necho hola >> hello\necho hola > hello >> hello >> hello\ncat < hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola >> hello >> hello > hello\necho hola >> hello\ncat < hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola >> hello >> hello > hello\necho hola >> hello\necho hola >> hello >> hello > hello\ncat < hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > hello\necho hola >> hello >> hello >> hello\necho hola >> hello\ncat < hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > hello\necho hey > bonjour\necho <bonjour <hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > hello\necho hey > bonjour\necho <hello <bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\nrm bonjour hello\necho hola > bonjour > hello > bonjour\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\necho hola > bonjour > hello > bonjour\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\nrm bonjour hello\necho hola > bonjour >> hello > bonjour\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\necho hola > bonjour > hello > bonjour\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\nrm bonjour hello\necho hola > bonjour > hello >> bonjour\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\necho hola > bonjour > hello >> bonjour\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\nrm bonjour hello\necho hola >> bonjour > hello > bonjour\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\necho hola >> bonjour > hello > bonjour\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\nrm bonjour hello\necho hola >> bonjour >> hello >> bonjour\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\necho hola >> bonjour >> hello >> bonjour\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `> bonjour echo hola bonjour\ncat bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `>bonjour echo > hola>bonjour>hola>>bonjour>hola hey >bonjour hola >hola\ncat bonjour\ncat hola`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo bonjour > hola1\necho hello > hola2\necho 2 >hola1 >> hola2\nls\ncat hola1\ncat hola2`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo bonjour > hola1\necho hello > hola2\necho 2 >>hola1 > hola2\nls\ncat hola1\ncat hola2`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `> pwd\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat > ls1 < ls2\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `>>hola\ncat hola`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\ncat < bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola >bonjour\ncat <bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola>bonjour\ncat<bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola> bonjour\ncat< bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola               >bonjour\ncat<                     bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola          >     bonjour\ncat            <         bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > srcs/bonjour\ncat < srcs/bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola >srcs/bonjour\ncat <srcs/bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho que tal >> bonjour\ncat < bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\nrm bonjour\necho que tal >> bonjour\ncat < bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `e'c'"h"o hola > bonjour\ncat 'bo'"n"jour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\ 1\nls\ncat bonjour\ 1`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour hey\nls\ncat bonjour\ncat hey`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > srcs/bonjour\necho hey > srcs/hello\n>srcs/bonjour >srcs/hello <prout\ncat srcs/bonjour srcs/hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > srcs/bonjour\necho hey > srcs/hello\nrm srcs/bonjour srcs/hello\n>srcs/bonjour >srcs/hello <prout\nls srcs\ncat srcs/bonjour srcs/hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > srcs/bonjour\necho hey > srcs/hello\n>srcs/bonjour <prout >srcs/hello\ncat srcs/bonjour\ncat srcs/hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > srcs/bonjour\necho hey > srcs/hello\nrm srcs/bonjour srcs/hello\n>srcs/bonjour <prout >srcs/hello\nls srcs\ncat srcs/bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > ../bonjour\necho hey > ../hello\n>../bonjour >../hello <prout\ncat ../bonjour ../hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > ../bonjour\necho hey > ../hello\nrm ../bonjour ../hello\n>../bonjour >../hello <prout\nls ..\ncat ../bonjour ../hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > ../bonjour\necho hey > ../hello\n>../bonjour <prout >../hello\ncat ../bonjour\ncat ../hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > ../bonjour\necho hey > ../hello\nrm ../bonjour ../hello\n>../bonjour <prout >../hello\nls ..\ncat ../bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > srcs/bonjour\necho hey > srcs/hello\n>srcs/bonjour >>srcs/hello <prout\ncat srcs/bonjour\ncat srcs/hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > srcs/bonjour\necho hey > srcs/hello\n>>srcs/bonjour >srcs/hello <prout\ncat srcs/bonjour\ncat srcs/hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > srcs/bonjour\necho hey > srcs/hello\n>>srcs/bonjour >>srcs/hello <prout\ncat srcs/bonjour\ncat srcs/hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > srcs/bonjour\necho hey > srcs/hello\n>srcs/bonjour <prout >>srcs/hello\ncat srcs/bonjour\ncat srcs/hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > srcs/bonjour\necho hey > srcs/hello\n>>srcs/bonjour <prout >srcs/hello\ncat srcs/bonjour\ncat srcs/hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > srcs/bonjour\necho hey > srcs/hello\n>>srcs/bonjour <prout >>srcs/hello\ncat srcs/bonjour\ncat srcs/hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > srcs/bonjour\necho hey > srcs/hello\n<prout >>srcs/bonjour >>srcs/hello\ncat srcs/bonjour\ncat srcs/hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\n<bonjour >hello\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\n>bonjour >hello < prout\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\nrm bonjour hello\n>bonjour >hello < prout\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\n>bonjour <prout hello\ncat bonjour\ncat hello`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\necho hey > hello\nrm bonjour hello\n>bonjour <prout hello\ncat bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > bonjour\n<bonjour cat | wc > bonjour\ncat bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `rm -f bonjour\nrm bonjour > bonjour\nls -l bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="bonjour hello"\n>$HOLA\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="bonjour hello"\n>"$HOLA"\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="bonjour hello"\n>$"HOLA"\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="bonjour hello"\n>$HOLA>hey\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="bonjour hello"\n>hey>$HOLA\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export HOLA="bonjour hello"\n>hey>$HOLA>hey>hey\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `export A=hey\nexport A B=Hola D E C="Que Tal"\necho $PROUT$B$C > /tmp/a > /tmp/b > /tmp/c\ncat /tmp/a\ncat /tmp/b\ncat /tmp/c`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `<a cat <b <c\ncat a\ncat b\ncat c`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `>a ls >b >>c >d\ncat a\ncat b\ncat c\ncat d`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `>a ls >b >>c >d\ncat a\ncat b\ncat c\ncat d`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola > a > b > c\ncat a\ncat b\ncat c`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `mkdir dir\nls -la > dir/bonjour\ncat dir/bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `<a\ncat a`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `>d cat <a >>e\ncat a\ncat d\ncat e`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `< a > b cat > hey >> d\ncat d\nls`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat << 'hola'`
**Reason**: Skipped: Heredoc with quotes or dollar sign in delimiter is out of scope (Note: Heredoc with quotes or dollar sign in delimiter is out of scope)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat << "hola"`
**Reason**: Skipped: Heredoc with quotes or dollar sign in delimiter is out of scope (Note: Heredoc with quotes or dollar sign in delimiter is out of scope)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat << ho"la"`
**Reason**: Skipped: Heredoc with quotes or dollar sign in delimiter is out of scope (Note: Heredoc with quotes or dollar sign in delimiter is out of scope)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat << $HOME`
**Reason**: Skipped: Heredoc with quotes or dollar sign in delimiter is out of scope (Note: Heredoc with quotes or dollar sign in delimiter is out of scope)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat << hola > bonjour\ncat bonjour`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `<< $hola`
**Reason**: Skipped: Heredoc with quotes or dollar sign in delimiter is out of scope (Note: Heredoc with quotes or dollar sign in delimiter is out of scope)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `<< $"hola"$"b"`
**Reason**: Skipped: Heredoc with quotes or dollar sign in delimiter is out of scope (Note: Heredoc with quotes or dollar sign in delimiter is out of scope)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `<< $"$hola"$$"b"`
**Reason**: Skipped: Heredoc with quotes or dollar sign in delimiter is out of scope (Note: Heredoc with quotes or dollar sign in delimiter is out of scope)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `<< ho$la$"$a"$$"b"`
**Reason**: Skipped: Heredoc with quotes or dollar sign in delimiter is out of scope (Note: Heredoc with quotes or dollar sign in delimiter is out of scope)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola <<< bonjour`
**Reason**: Skipped: Here strings '<<<' are not required by the subject (Note: Here strings '<<<' are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola <<<< bonjour`
**Reason**: Skipped: Here strings '<<<' are not required by the subject (Note: Here strings '<<<' are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `echo hola <<<<< bonjour`
**Reason**: Skipped: Here strings '<<<' are not required by the subject (Note: Here strings '<<<' are not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat << EOF\nhello\nworld\nEOF`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat << EOF\nhello $USER\nEOF`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat << EOF\nexit status is $?\nEOF`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat << LIMITER\nline1\nline2\nLIMITER | grep line1`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat << EOF1 << EOF2\ninside1\nEOF1\ninside2\nEOF2`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `<< EOF\nline\nEOF`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat << EOF\n\nEOF`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

### Mismatch for Command: `cat << EOF\n$DONT_EXIST\nEOF`
**Reason**: Skipped: Backslash '\' is not required by the subject (Note: Backslash '\' is not required by the subject)

#### 💻 BASH baseline
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

#### 🐚 MINISHELL (`./minishell`) tested
- **Exit Status**: `0`
- **Stdout**: *(Empty)*
- **Stderr**: *(Empty)*

---

