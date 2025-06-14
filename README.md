# 🐚 Minishell

## 👥 Collaborators

<a href="https://github.com/Daniela-Padilha/minishell/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=Daniela-Padilha/minishell" />
</a>

Made with [contrib.rocks](https://contrib.rocks).

## About  
Minishell is the first group project at 42 school, where the goal is to create a simplified Unix shell written in C, capable of handling input parsing, command execution, redirections, pipes, environment variables, and signal management, all without relying on system shells like `/bin/sh`.

This project explores how shells work internally, including parsing logic, process control, and I/O redirection.

---

## 🛠️ Build  

Clone the repository:

`git clone https://github.com/your-username/minishell.git`

Enter the project directory:

`cd minishell`

Compile the shell:

`make`

## ▶️ Usage example
Run the shell:

`./minishell`

You can now type commands as in a regular terminal:

`echo "Hello world"
ls -l | grep minishell > result.txt
export NAME=42 && echo $NAME
cat << EOF
This is a heredoc.
EOF`

If a command is invalid, the shell will print a meaningful error, similar to bash.

## ✅ Supported features
### Minishell includes:

- Line editing and history with readline

- Syntax validation (quotes, pipes, redirections)

- Tokenization and parsing of command lines

- Abstract Syntax Tree (AST) construction for execution flow

### Execution of:

- Built-in commands (cd, echo, pwd, export, unset, env, exit)

- External programs via execve

- Pipes and multiple chained commands

- Redirections: >, >>, <

- Heredocs with optional expansion (<<)

- Environment variable handling

- Signal handling (Ctrl+C, Ctrl+\\, Ctrl+D)

- Exit status tracking with $?

## 💡 Project rules and behavior
Only && and || are not supported (per subject instructions)

Built-ins are executed in the parent process when needed (e.g., cd, exit)

Heredocs are processed with support for multiple inputs per line

Quoted text is preserved as expected

`$VAR`, `$?`, and other shell expansions are handled with proper quoting behavior

## 📌 Examples of handled input

`ls -a | grep .c > files.txt
echo "$USER home is $HOME"
cat << EOF | wc -l
Hello
42
EOF
export VAR=test && echo $VAR
cd invalid_dir`

## 🧪 Tests

The project includes a thorough collection of **282 manual tests** designed to verify the correctness and robustness of the minishell implementation. These tests cover various features such as builtins, expansions, redirections, piping, error handling, and signal management.

Currently, these tests are documented as a detailed checklist rather than an automated script. You can use them as a reference to manually verify your shell behaves as expected and to guide your development and debugging process.

We recommend running these tests step-by-step to ensure your minishell matches bash-like behavior in all tested scenarios.

<p align="center">
  <strong><a href="https://www.notion.so/meeru/1d02544e44e2807d9013fd3eefbfebf4?v=1d02544e44e28087a970000c7fb78979">TEST LIST</a></strong>
</p>

