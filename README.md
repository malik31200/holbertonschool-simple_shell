```
 _____ _                 _        _____ _          _ _ 
/  ___(_)               | |      /  ___| |        | | |
\ `--. _ _ __ ___  _ __ | | ___  \ `--.| |__   ___| | |
 `--. \ | '_ ` _ \| '_ \| |/ _ \  `--. \ '_ \ / _ \ | |
/\__/ / | | | | | | |_) | |  __/ /\__/ / | | |  __/ | |
\____/|_|_| |_| |_| .__/|_|\___| \____/|_| |_|\___|_|_|
                  | |                                  
                  |_|                                  
```
# 🐚 Simple shell
## 🔖 Table of contents

<details>
  <summary>
    CLICK TO ENLARGE 😇
  </summary>
  📄 <a href="#description">Description</a>
  <br>
  🎓 <a href="#objectives">Objectives</a>
  <br>
  🔨 <a href="#tech-stack">Tech stack</a>
  <br>
  📝 <a href="#feature">Feature</a>
  <br>
  👾 <a href="#valgrind">Valgrind</a>
  <br>
  💾 <a href="#builtins">Builtins</a>
  <br>
  🗒️ <a href="#man">Man</a> 
  <br>
  📂 <a href="#files-description">Files description</a>
  <br>
  💻 <a href="#installation">Installation</a>
  <br>
  🔍 <a href="#how-to-use">How to Use</a>
  <br>
  🚨 <a href="#known-bug">Known bug</a> 
  <br>
  🔧 <a href="#whats-next">What's next?</a>
  <br>
  ♥️ <a href="#thanks">Thanks</a>
  <br>
  👷 <a href="#authors">Authors</a>
  </details>

## 📄 <span id="description">Description</span>

A simple shell project for holberton school, the project must be betty compliant,
must use specific compilation processes and have to pass holberton checker

## 🎓 <span id="objectives">Objectives</span>

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- Handle errors.
- Handle the “end of file” condition (Ctrl+D)
- Handle command lines with arguments
- Handle the PATH
- Fork must not be called if the command doesn’t exist

## 📝 <span id="feature">Feature</span>
- builtins such as `exit`, `env` etc...
- handle abstract commands like `ls`, `pwd` etc..
- handle relative or absolute command path `/bin/ls`
- handles arguments like `ls -la`

## 👾 <span id="valgrind">Valgrind</span>

The project was regularly tested with valgrind to prevent memory leaks
```bash
==4358==
==4358== HEAP SUMMARY:
==4358==     in use at exit: 0 bytes in 0 blocks
==4358==   total heap usage: 104 allocs, 104 frees, 4,270 bytes allocated
==4358==
==4358== All heap blocks were freed -- no leaks are possible
==4358==
==4358== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

This proves that the project is memory safe and leak free.
## 🗒️ <span id="man">Man</span>
### groff
Install groff
```bash
sudo apt-get install groff
```
Run groff
```bash
groff -k -Tutf8 -man man_1_simple_shell
```

### man
Run
```bash
man ./man_1_simple_shell
```
## 💾 <span id="builtins">Builtins</span>
- `exit` - exit the shell properly
- `env` - print the environement variables in the standard output

## 🔨 <span id="tech-stack">Tech stack</span>

<p align="left">
<img src="https://img.shields.io/badge/VIM-3EB535?logo=vim&logoColor=white&style=for-the-badge" alt="VIM badge">

<img src="https://img.shields.io/badge/GIT-D68936?logo=git&logoColor=white&style=for-the-badge" alt="GIT badge">

<img src="https://img.shields.io/badge/GITHUB-000000?logo=github&logoColor=white&style=for-the-badge" alt="GITHUB badge">

<img src="https://img.shields.io/badge/C-2FA5BA?logo=c&logoColor=white&style=for-the-badge" alt="C badge">

</p>

## 📂 <span id="files-description">File description</span>

| **FILE**            | **DESCRIPTION**                                   |
| :-----------------: | ------------------------------------------------- |
| [`.gitignore`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/.gitignore)       | A file that defines the rules for what the repo accepts or not                          |
| [`README.md`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/README.md)     | Doc README.md file                       |
| [`man_1_simple_shell`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/man_1_simple_shell)      | man page for the simple shell project |
| [`AUTHORS`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/AUTHORS)      | Automatically generated Author page     |
| [`hack`](https://github.com/malik31200/holbertonschool-simple_shell/tree/main/hack)       | Contain utility tools for generating AUTHOR files   |
| [`built_in.c`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/built_in.c)       | Contains functions to deal with builtins `env` `exit`|
| [`env.c`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/env.c)       | Contains utility functions for the environement to deal with path |
| [`env.h`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/env.h)       | Header file for env utilities |
| [`execute.c`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/execute.c)       | Contains utility function that deals with executing a command |
| [`main.c`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/main.c)       | Program entry point |
| [`memory.c`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/memory.c)       | Contains utility functions for dealing with memory |
| [`path_or_no_path.c`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/path_or_no_path.c)       | COntains utility functions for dealing with abstract commands like `ls` and absolute path ones like `/bin/ls`|
| [`shell.h`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/shell.h)       | Header file containing all the necessary functions to run the shell |
| [`split_token.c`](https://github.com/malik31200/holbertonschool-simple_shell/blob/main/split_token.c)       | Contain Utility functions for dealing with tokens |

## 💻 <span id="installation">Installation</span>

1. Clone this repository:
  - Open your preferred Terminal.
  - Navigate to the directory where you want to clone the repository.
  - Run the following command:

```bash
git clone https://github.com/malik31200/holbertonschool-simple_shell
```

2. Open the repository you've just cloned.

3. Compile with this command

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## 🔍 <span id="how-to-use">How to use</span>
### run (interactive mode)
```bash
./hsh
```

```bash
($) /bin/ls
AUTHORS  build  built_in.c  env.c  env.h  execute.c  exercice_shell  hack  hsh  main.c  man_1_simple_shell  memory.c  obj  path_or_no_path.c  README.md  shell.h  split_token.c  test_ls_2
($) exit
```

### run (non interactive mode)
```bash
echo "/bin/ls" | ./hsh
AUTHORS  build  built_in.c  env.c  env.h  execute.c  exercice_shell  hack  hsh  main.c  man_1_simple_shell  memory.c  obj  path_or_no_path.c  README.md  shell.h  split_token.c  test_ls_2
```


## 🚨 <span id="known-bug">Known bug</span>
- no known bugs were found so far

## 🔧 <span id="whats-next">What's next?</span>

- pipe integration `|`
- background process integration `&`
- redirections `<` & `>`
- command separator `;`

## ♥️ <span id="thanks">Thanks</span>

Thanks for my peers, Franck, Hugo for the help during the project

## 👷 <span id="authors">Authors</span>

**Adel MEJRISSI**
- GitHub: [@AdelMej](https://github.com/AdelMej)
- LinkedIn: [@adel-mejrissi](https://www.linkedin.com/in/adel-mejrissi-709374172)

**Malik Bouanani**
- GitHub: [@malik31200](https://github.com/malik31200)

