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

The goal of the project is to make a simple shell that should run in ubuntu LTS 20.4

## 🎓 <span id="objectives">Objectives</span>

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- handle the “end of file” condition (Ctrl+D)
- handle path (fork() only if the file exist and is executable)
- handle exit builtin

## 🔨 <span id="tech-stack">Tech stack</span>

<p align="left">
<img src="https://img.shields.io/badge/VIM-3EC76A?logo=vim&logoColor=white&style=for-the-badge" alt="VIM badge">
<img src="https://img.shields.io/badge/GITHUB-000000?logo=github&logoColor=white&style=for-the-badge" alt="GITHUB badge">
<img src="https://img.shields.io/badge/GIT-D98318?logo=git&logoColor=white&style=for-the-badge" alt="GIT badge">
<img src="https://img.shields.io/badge/C-18ACD9?logo=c&logoColor=white&style=for-the-badge" alt="C badge">
</p>

## 📂 <span id="files-description">File description</span>

| **FILE**            | **DESCRIPTION**                                   |
| :-----------------: | ------------------------------------------------- |
| `file_name`       | Description of the file.                          |
| `folder_name`     | Description of the folder.                        |
| `.gitignore`      | Specifies files and folders to be ignored by Git. |
| `README.md`       | The README file you are currently reading 😉.     |
| `README.md`       | The README file you are currently reading 😉.     |
| `README.md`       | The README file you are currently reading 😉.     |
| `README.md`       | ATHOR     |


## 💻 <span id="installation">Installation</span>

1. Clone this repository:
  - Open your preferred Terminal.
  - Navigate to the directory where you want to clone the repository.
  - Run the following command:

```bash
git clone <link_to_the_repository>
```

2. Open the repository you've just cloned.

3. Compile the program
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

4. you can now use your binary called hsh

## 🔧 <span id="whats-next">What's next?</span>

- advanced features like cd builtin

## ♥️ <span id="thanks">Thanks</span>

- Thanks for everything this project was a nightmare 😮‍💨
- apparently you get shutdown if you do too much 🫠
- prep vanished

## 👷 <span id="authors">Authors</span>

**Adel Mejrissi**
- GitHub: [@AdelMej](https://github.com/AdelMej)
- LinkedIn: [@adle-mejrissi](https://www.linkedin.com/in/adel-mejrissi-709374172/)
