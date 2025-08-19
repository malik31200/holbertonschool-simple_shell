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
  📂 <a href="#files-description">Files description</a>
  <br>
  💻 <a href="#installation">Installation</a>
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

## 💾 builtins
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
| `file_name`       | Description of the file.                          |
| `folder_name`     | Description of the folder.                        |
| `.gitignore`      | Specifies files and folders to be ignored by Git. |
| `README.md`       | The README file you are currently reading 😉.     |



## 💻 <span id="installation">Installation</span>

1. Clone this repository:
  - Open your preferred Terminal.
  - Navigate to the directory where you want to clone the repository.
  - Run the following command:

```bash
git clone https://github.com/malik31200/holbertonschool-simple_shell
```
## 

2. Open the repository you've just cloned.

3. Compile with this command

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## 🔍 How to use
### run (interactive mode)
```bash
./hsh
```


### run (non interactive mode)
```bash
echo "/bin/ls" | ./hsh
```

## 🚨 known bug


## 🔧 <span id="whats-next">What's next?</span>

- pipe integration `|`
- background process integration `&`
- redirections `<` & `>`
- command separator `;`

## ♥️ <span id="thanks">Thanks</span>

- Your message of thanks here. 

## 👷 <span id="authors">Authors</span>

**Adel MEJRISSI**
- GitHub: [@AdelMej](https://github.com/AdelMej)
- LinkedIn: [@adel-mejrissi](https://www.linkedin.com/in/adel-mejrissi-709374172)

**Malik Bouanani**
- GitHub: [@malik31200](https://github.com/malik31200)

